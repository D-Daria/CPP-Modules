#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::~Point()
{
	// std::cout << "Point destructor called" << std::endl;
}

Point::Point(const float fx, const float fy) : x(fx), y(fy) {}

Point::Point(const Point &point) : x(point.getX()), y(point.getY())
{
	*this = point;
}

Point &Point::operator=(const Point &point)
{
	if (this != &point)
	{
		return (*this);
	}
	return (*this);
}

const Fixed	&Point::getX() const
{
	return (x);
}

const Fixed	&Point::getY() const
{
	return (y);
}

std::ostream& operator<<(std::ostream& os, const Point& point)
{
	os << "[" << point.getX() << "; " << point.getY() << "]" << std::endl;
    return os;
}
