#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

	private:
		int m_fixedPointVal;
		static const int m_fractBits;

	public:
		Fixed(); //contructor

		Fixed(const Fixed &fixed); //copy constructor

		Fixed &operator=(const Fixed &fixed); //copy assignment operator

		~Fixed(); //destructor

		Fixed(int const raw);
		Fixed(float const fRaw);

		float toFloat(void) const;
		int toInt(void) const;

		int getRawBits(void) const;
		void setRawBits(int const raw);

		//overloading comparison operators: >, <, >=, <=, ==, !=.
		bool operator>(const Fixed &fix);
		bool operator<(const Fixed &fix);
		bool operator>=(const Fixed &fix);
		bool operator<=(const Fixed &fix);
		bool operator==(const Fixed &fix);
		bool operator!=(const Fixed &fix);

		//overloading arithmetic operators: +, -, *, /
		float operator+(const Fixed &fix);
		float operator-(const Fixed &fix);
		float operator*(const Fixed &fix);
		float operator/(const Fixed &fix);

		//overloading increment/decrement
		//preincrement
		Fixed &operator++();
		//postincrement
		Fixed operator++(int);
		//predecrement
		Fixed &operator--();
		//postdecrement
		Fixed operator--(int);

		//public overloaded functions
		static Fixed &min(Fixed &fix1, Fixed &fix2);
		static const Fixed &min(Fixed const &fix1, Fixed const &fix2);
		static Fixed &max(Fixed &fix1, Fixed &fix2);
		static const Fixed &max(Fixed const &fix1, Fixed const &fix2);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif