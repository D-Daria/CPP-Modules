#include "Conversion.hpp"

Conversion::Conversion(){};

Conversion::Conversion(const Conversion &copyConversion)
{
	m_input = copyConversion.getInput();
	m_type = copyConversion.getType();
	*this = copyConversion;
}

Conversion &Conversion::operator=(const Conversion &conversion)
{
	if (this == &conversion)
		return (*this);
	m_input = conversion.getInput();
	m_type = conversion.getType();
	return (*this);
}

Conversion::~Conversion(){};

Conversion::Conversion(std::string str) : m_input(str)
{
	convert();
}

int Conversion::validateInput(void)
{
	std::string str = getInput();
	if (str.length() == 1 && isascii(str[0]) && !isdigit(str[0]))
		return (CHAR);
	char *end;
	strtod(str.c_str(), &end);
	if (*end == 'f' && strlen(end) == 1)
		return (FLOAT);
	if (isdigit(*end) && str.find('.') != std::string::npos)
		return (DOUBLE);
	if (*end == 0)
		return (INT);
	return (0);
}

void Conversion::displayChar(void)
{
	if (getType() == CHAR)
	{
		if (isprint(getInput()[0]))
			std::cout << "char:\t'" << getInput()[0] << "'" << std::endl;
		else
			std::cout << "char:\t" << "Non displayable" << std::endl;
		return ;
	}
	if (isnan(getlDouble()) || isinf(getlDouble())
			|| getlDouble() >= std::numeric_limits<char>::max() || getlDouble() < 0)
		std::cout << "char:\timpossible" << std::endl;
	else if (isprint(toChar()))
		std::cout << "char:\t'" << toChar() << "'" << std::endl;
	else
		std::cout << "char:\t" << "Non displayable" << std::endl;
}

void Conversion::displayInt(void)
{
	if (isnan(getlDouble()) || isinf(getlDouble()) 
		|| getlDouble() >= std::numeric_limits<int>::max() 
		|| getlDouble() <= std::numeric_limits<int>::min())
	{
		std::cout << "int:\t" << "impossible" << std::endl;
		return ;
	}
	if (getType() == INT)      
	{
		std::cout << "int:\t" << atoi(getInput().c_str()) << std::endl;
		return ;
	}
	else
		std::cout << "int:\t" << toInt() << std::endl;
}

void Conversion::displayFloat(void)
{
	if (getType() == FLOAT)
	{
		float f = atof(getInput().c_str());
		if (f - toInt() == 0)
			std::cout << "float:\t" << f <<  ".0f" << std::endl;
		else
			std::cout << "float:\t" << f <<  "f" << std::endl;
		return ;
	}
	if (toFloat() - toInt() == 0)
		std::cout << "float:\t" << toFloat() << ".0f" << std::endl;
	else
		std::cout << "float:\t" << toFloat() << "f" << std::endl;
}

void Conversion::displayDouble(void)
{
	if (getType() == DOUBLE)
	{
		double d = atof(getInput().c_str());
		if (d - toInt() == 0)
			std::cout << "double:\t" << d <<  ".0" << std::endl;
		else
			std::cout << "double:\t" << d << std::endl;
		return ;
	}
	if (toFloat() - toInt() == 0)
		std::cout << "double:\t" << toDouble() << ".0" << std::endl;
	else
		std::cout << "double:\t" << toDouble() << std::endl;
}

void Conversion::display(void)
{
	displayChar();
	displayInt();
	displayFloat();
	displayDouble();
}

void Conversion::convert(void)
{
	m_type = validateInput();
	if (getType() == 0)
		throw(ConversionImpossibleException());
	display();
}

std::string Conversion::getInput(void) const
{
	return (m_input);
}

int Conversion::getType(void) const
{
	return (m_type);
}

char Conversion::toChar(void)
{
	return static_cast<char>(getlDouble());
}

int Conversion::toInt(void)
{
	return static_cast<int>(getlDouble());
}

float Conversion::toFloat(void)
{
	return static_cast<float>(getlDouble());
}

double Conversion::toDouble(void)
{
	return static_cast<double>(getlDouble());
}

long double Conversion::getlDouble(void)
{
	if (getInput().length() == 1 && !isdigit(getInput()[0]))
		m_inputVal = static_cast<double>(getInput()[0]);
	else
		m_inputVal = atof(getInput().c_str());
	return (m_inputVal);
}
