#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

	private:
		int m_fixedPointNum;
		static const int m_fractBits;

	public:
		Fixed(); //contructor

		Fixed(const Fixed &fixed); //copy constructor

		Fixed &operator=(const Fixed &fixed); //copy assignment operator

		~Fixed(); //destructor

		int getRawBits(void) const;
		void setRawBits(int const raw);

};

#endif