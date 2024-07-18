#include "Ball.h"

#include <cmath>
#include <iostream>
using namespace std;

Ball::Ball(float x, float y): Circle(x, y, 10 )
{
	_ballImage.loadFromFile("whiteball.png");
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

	double lenght = sqrt(_vx * _vx + _vy * _vy);
	double sinalpha = _vy / lenght;
	double cosalpha = _vx / lenght;

	lenght*=.998881;
	_vx = lenght * cosalpha;
	_vy = lenght * sinalpha;

	if (abs( _vx) < 0.003 ) {
		_vx = 0;
	}
	if (abs(_vy) < 0.003) {
		_vy = 0;
	}

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
	shape->setTexture(&_ballImage);
	shape->setPointCount(1000);

	return shared_ptr<sf::Shape>(shape);
}
