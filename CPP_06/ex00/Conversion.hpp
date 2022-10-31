#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"

#define CHAR		1
#define INT			2
#define FLOAT		3
#define DOUBLE		4
#define MIN_INFF	5
#define INFF		6
#define NANF		7
#define MIN_INF		8
#define INF			9
#define	NAN			10

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>		/* strtod */
#include <cctype>		/* isprint */
#include <exception>
// #include <math.h>       /* isnan */
#include <cmath>       /* isnan */


class Conversion {

	private:
		std::string m_input;
		long double m_inputVal;
		int	m_type;

		int validateInput(void);
		void convert(void);
		void display(void);

		std::string getInput(void) const;
		int getType(void) const;
		long double getlDouble(void);

		void displayChar(void);
		void displayInt(void);
		void displayFloat(void);
		void displayDouble(void);

		char toChar(void);
		int toInt(void);
		float toFloat(void);
		double toDouble(void);

	public:
		Conversion();
		Conversion(const Conversion &copyConversion);
		Conversion &operator=(const Conversion &conversion);
		~Conversion();
		Conversion(std::string str);

		class ConversionImpossibleException : public std::exception {
			public:
				virtual const char* what() const throw()
				{
					return ("Conversion to char, int, float or double is impossible");
				}
		};
};

#endif