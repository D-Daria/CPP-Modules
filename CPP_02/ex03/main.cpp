#include "Point.hpp"

void result(Point a, Point b, Point c, Point point)
{
	std::cout << "a: " << a;
	std::cout << "b: " << b;
	std::cout << "c: " << c;
	std::cout << "Point:" << point;
	if (bsp(a, b, c, point) == true)
		std::cout << GREEN << "is inside the triangle\n" << RESET << std::endl;
	else
		std::cout << RED << "is outside the triangle\n" << RESET << std::endl;
}

int main(void)
{
	{
		// should be outside
		Point a(1, -6);
		Point b(5, -1.5);
		Point c(9, -6);
		Point point(4.5, -2);
		result(a, b, c, point);
	}
	{
		// should be inside
		Point a(-1.5, -1.5);
		Point b(2.5, 2.5);
		Point c(-1, -2);
		Point point(0.5, 0.1);
		result(a, b, c, point);
	}
	{
		// should be inside triangle
		Point a(0, 3.02f);
		Point b(5, 3.02f);
		Point c(2.5f, 0);
		Point point(1.5f, 1.5f);
		result(a, b, c, point);
	}
	{
		// point is vertice - false
		Point a(5.12, 4.16);
		Point b(1.18, -6.49);
		Point c(0, 0);
		// point is vertex - false
		Point point(0.0, 0.0);
		result(a, b, c, point);
		// true
		Point p1 = Point(0.3f, -0.1f);
		Point p2 = p1;
		result(a, b, c, p2);
	}
	{
		Point a(-6, -5);
		Point b(-6, -1);
		Point c(-2, -5);
		// outside - on the edge
		Point p1(-6, -3);
		result(a, b, c, p1);
		// inside 
		Point p2(-5.0f, -4.5f);
		result(a, b, c, p2);
	}
	{
		// triangle is impossible
		Point a(5.12, 4.16);
		Point b(5.12, 4.16);
		Point c(0, 0);
		Point point(2.56f, 2.08f);
		result(a, b, c, point);
	}
	{
		Point a = Point(0, 0);
		Point b = Point(0, 2);
		Point c = Point(2, 0);
		// inside
		Point p1 = Point(0.99f, 0.99f);
		result(a, b, c, p1);
		// on edge
		Point p2 = Point(1, 1);
		result(a, b, c, p2);
		// outside of the hypotenuse
		Point p3 = Point(1.01f, 1.01f);
		result(a, b, c, p3);
	}
	return (1);
}
