#include "Point.hpp"

bool checkTriangle(Point a, Point b, Point c)
{
	Fixed area;

	area = (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) + 
			b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) + 
			c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()));

	if (area == 0)
		return (false);
	return (true);
}

Fixed	getTurn(Point vec1, Point vec2, Point p)
{
	Fixed vec1_x = vec2.getX().toFloat() - vec1.getX().toFloat();
	Fixed vec1_y = vec2.getY().toFloat() - vec1.getY().toFloat();

	Fixed vec2_x = p.getX().toFloat() - vec1.getX().toFloat();
	Fixed vec2_y= p.getY().toFloat() - vec1.getY().toFloat();

	Fixed res = vec1_x * vec2_y - vec1_y * vec2_x;

	return (res);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (checkTriangle(a, b, c) == false)
		return (false);

	Fixed abp = getTurn(a, b, point);
	Fixed bcp = getTurn(b, c, point);
	Fixed cap = getTurn(c, a, point);

	if (abp > 0 && bcp > 0 && cap > 0)
		return (true);
	if (abp < 0 && bcp < 0 && cap < 0)
		return (true);
	return (false);
}
