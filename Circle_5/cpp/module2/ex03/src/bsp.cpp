#include "Point.hpp"

static Fixed	calculateArea(const Point& a, const Point& b, const Point& c)
{
	Fixed	area;

	area = ((a.getX() * (b.getY() - c.getY())
			+ b.getX() * (c.getY() - a.getY()) 
			+ c.getX() * (a.getY() - b.getY())) / Fixed(2));

	if (area < Fixed(0))
		area = area * Fixed(-1);
	return area;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	areaABC = calculateArea(a, b, c);

	if (areaABC == Fixed(0))
		return false;
	
	Fixed	areaPAB = calculateArea(point, a, b);
	Fixed	areaPBC = calculateArea(point, b, c);
	Fixed	areaPCA = calculateArea(point, c, a);
	if (areaPAB == Fixed(0) || areaPBC == Fixed(0) || areaPCA == Fixed(0))
		return false;
	if ((areaPAB + areaPBC + areaPCA) == areaABC)
		return true;
	else
		return false;
}