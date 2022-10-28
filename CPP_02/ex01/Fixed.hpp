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

};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif