#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	fillDatabase();
}

BitcoinExchange::BitcoinExchange(std::string filename)
{
	fillDatabase();
	inputFile = filename;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &btcCopy)
{
	*this = btcCopy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &btcCopy)
{
	if (this == &btcCopy)
		return *this;
	return *this;
}

bool openFile(std::ifstream &sfile, std::string &filename)
{
	sfile.open(filename);
	if (sfile.is_open() == false)
		return false;
	return true;
}

Date parseDate(std::string str, char sep)
{
	std::stringstream ss;
	std::replace(str.begin(), str.end(), sep, ' ');
	ss << str;
	long year, month, day;
	ss >> year >> month >> day;
	if (year >= 2023 || year <= 2000
		|| month <= 0 || month >= 13
		|| day <= 0 || day > 31)
	{
		return Date(0, 0, 0);
	}
	return Date(year, month, day);
}

void BitcoinExchange::fillDatabase()
{
	std::ifstream db;

	db.open(dbName);
	if (db.is_open() == false)
		throw(BitcoinExchangeException("failed to open db file"));
	size_t pos = 0;
	std::string line = "";
	std::string date = "";
	double val;
	while (std::getline(db, line, '\n'))
	{
		pos = line.find(',');
		if (pos != std::string::npos && line.substr(0, pos) != "date") {
			date = line.substr(0, pos);
			std::stringstream ss(line.substr(pos + 1, strlen(line.c_str()) - pos).c_str());
			ss >> val;
			Date dt = parseDate(date, '-');
			database.insert(std::pair<Date, float>(dt, val));
		}
	}
}

void output(Date &date, float &value, float &exch)
{
	std::cout << date << " => " << value << " = " << exch << std::endl;
}

void errorOutput(std::string const &msg, std::string const &val)
{
	std::cerr << "Error: " << msg << val << std::endl;
}

float BitcoinExchange::findClosest(Date &date)
{
	t_tm tmInner;
	time_t rawtimeInner;

	t_tm tmDate;
	time_t rawtimeDate;
	time(&rawtimeDate);
	tmDate = *localtime(&rawtimeDate);
	tmDate.tm_year = date.year - 1900;
	tmDate.tm_mon = date.month - 1;
	tmDate.tm_mday = date.day;
	time_t dt = mktime(&tmDate);

	std::map<Date, float>::iterator it = database.begin();
	std::map<Date, float>::iterator end = database.end();
	double diff = std::numeric_limits<double>::max();
	double sub;
	float res  = 0.0;
	while(it != end)
	{
		time(&rawtimeInner);
		tmInner = *localtime(&rawtimeInner);
		tmInner.tm_year = it->first.year - 1900;
		tmInner.tm_mon = it->first.month - 1;
		tmInner.tm_mday = it->first.day;
		sub = dt - mktime(&tmInner);
		if (sub < diff && sub > 0)
		{
			diff = sub;
			res = it->second;
		}
		if (sub < 0)
			break;
		it++;
	}
	return res;
}

void BitcoinExchange::fillMap(std::ifstream &file, char sep)
{
	size_t pos = 0;
	std::string line = "";
	std::string date = "";
	float val = 0;
	float exch = 0;
	std::getline(file, line, '\n');
	std::remove(line.begin(), line.end(), ' ');
	if (line.find("date|value") == std::string::npos)
		throw (BitcoinExchangeException("invalid input file"));
	while (std::getline(file, line, '\n'))
	{
		bool isError = false;
		line.erase(line.find_last_not_of(" \n\r\t") + 1);
		pos = line.find(sep);
		if (pos != std::string::npos && line.find("date") == std::string::npos) {
			date = line.substr(0, pos);
			if (pos + 1 == line.size()) {
				errorOutput("no value.", "");
				isError = true;
			}
			std::stringstream ss(line.substr(pos + 1, strlen(line.c_str()) - pos).c_str());
			ss >> val;
			if (val < 0)
			{
				errorOutput("not a positive number.", "");
				isError = true;
			}
			if (val > 1000)
			{
				errorOutput("too large number.", "");
				isError = true;
			}
			Date dt = parseDate(date, '-');
			if (dt.year <= 2000 || dt.year >= 2023 \
				|| dt.month <= 0 || dt.month > 12 \
				|| dt.day <= 0 || dt.day > 31)
			{
				errorOutput("bad input => ", date);
				isError = true;
			}
			if (isError) {
				continue;
			}
			if (database.find(dt) == database.end())
				exch = findClosest(dt) * val;
			else
				exch = database[dt] * val;
			output(dt, val, exch);
		}
		if (pos == std::string::npos)
			errorOutput("bad input => ", line);
	}
}

void BitcoinExchange::exchange()
{
	std::ifstream file;

	if (openFile(file, inputFile) == false)
		throw (BitcoinExchangeException("failed to open input file"));
	fillMap(file, '|');
}

std::map<Date, float> BitcoinExchange::getDatabase() const
{
	return database;
}
