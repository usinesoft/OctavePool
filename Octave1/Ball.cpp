#include "Ball.h"

#include <cmath>
#include <iostream>
using namespace std;

Ball::Ball(float x, float y): Circle(x, y, 10 )
{

}

void Ball::shoot(float vx, float vy)
{
	_vx=vx;
	_vy=vy;
}
void Ball::advance()
{
	_x=_x+_vx;
	_y=_y+_vy;
}

bool Ball::isCollisionY (float yWall)
{
	float distWall= abs(yWall-_y-_radius);


	if(distWall < 3)
		return true;

	return false;

}
void Ball::bounceY()
{
	_vy=-_vy;

}

bool Ball::isCollisionX (float xWall)
{
	float distWall= abs( xWall-_x-_radius);

	if(distWall < 3)
		return true;

	return false;

}
void Ball::bounceX()
{
	_vx=-_vx;
}

shared_ptr<sf::Shape> Ball::getShape() const
{
	const auto shape = new sf::CircleShape(_radius);
	shape->setPosition(_x, _y);

	return shared_ptr<sf::Shape>(shape);
}
