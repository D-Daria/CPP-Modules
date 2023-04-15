# ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

#include "Date.hpp"
#include <map>
#include <fstream>
#include <sstream>
#include <ctime>
#include <climits>

# define dbName		"data.csv"
# define BADINPUT	"bad input => "

typedef struct tm t_tm;

class BitcoinExchange {

	private:
		std::map<Date, float> database;
		std::map<Date, float> inputValues;
		std::string	inputFile;

	public:
		BitcoinExchange();
		BitcoinExchange(std::string filename);
		BitcoinExchange(const BitcoinExchange &copyBExch);
		BitcoinExchange &operator=(const BitcoinExchange &BExch);
		~BitcoinExchange();

		void fillDatabase();
		void fillMap(std::ifstream &file, char sep);

		std::map<Date, float> getDatabase() const;

		float findClosest(Date &date);

		void exchange();

		class BitcoinExchangeException : public std::exception {
			private:
				const char *message;

			public:
				BitcoinExchangeException(const char *msg) : message(msg) {}

				virtual const char* what() const throw() {
					std::cerr << "Error: ";
					return (message);
				}
		};

};

Date parseDate();
bool openFile(std::ifstream &sfile, std::string &filename);

# endif