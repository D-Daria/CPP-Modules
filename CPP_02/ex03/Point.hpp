#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {

	private:
		const Fixed x;
		const Fixed y;

	public:
		Point();
		Point(const float fx, const float fy);
		Point(const Point &point);
		Point &operator=(const Point &point);
		~Point();

		const Fixed &getX() const;
		const Fixed &getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
std::ostream &operator<<(std::ostream &os, const Point &point);

#endif