#include "Circle.h"

#include <iostream>

using namespace std;

Circle::Circle(float x, float y, float radius )
{
	_x = x;
	_y = y;
	_radius = radius;
}
void Circle::moveTo(float x, float y)
{
	_x = x;
	_y = y;
}
void Circle::move(float dX, float dY)
{
	_x = _x+dX;
	_y = _y+dY;
}



float Circle::minimumDistance(Circle otherCircle) const
{
	float dX = otherCircle._x - _x;
	float dY = otherCircle._y - _y;
	float dCenter = sqrt(dX*dX + dY*dY);
	float minimumDistance = dCenter - (_radius + otherCircle._radius);
	return minimumDistance;
}
void Circle::display()
{
	cout << "x=" << _x << " y=" <<_y << " radius=" << _radius << endl;
}
float Circle::distanceToCenter(Circle otherCircle) const
{
	return sqrt((_x - otherCircle._x) *(_x - otherCircle._x)+(_y - otherCircle._y) *(_y - otherCircle._y));
}

