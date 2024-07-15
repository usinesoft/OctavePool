#include "Cue.h"

#include <cmath>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

void Cue::computeVxVy()
{
	const float alphaRad = (3.14159265 / 180) * _alpha;

	_vy = _lenght * sin(alphaRad) / 30;

	_vx = _lenght * cos(alphaRad) / 30;

	

}

Cue::Cue(float xBall, float yBall):_xBall(xBall), _yBall(yBall), _lenght(20), _alpha(45)
{
	computeVxVy();
}

std::shared_ptr<sf::Shape> Cue::getShape() const
{
	
	sf::RectangleShape* line = new sf::RectangleShape(sf::Vector2f(_lenght, 2));
	
	line-> setPosition(sf::Vector2f(_xBall + 10, _yBall + 10));
	
	line -> setFillColor(sf::Color(180, 10, 10));

	line->rotate(_alpha);

	return std::shared_ptr<sf::Shape>(line);

}

void Cue::rotateUp()
{
	_alpha+=1;
	computeVxVy();

}

void Cue::rotateDown()
{
	_alpha-=1;
	computeVxVy();
}

void Cue::stronger()
{
	if (_lenght<=50 )
	{
		_lenght++;
		computeVxVy();
	}
}
void Cue::weaker()
{
	if (_lenght>=20 )
	{
		_lenght--;
		computeVxVy();
	}
}
float Cue::get_vX()
{
	return _vx;
}
float Cue::get_vY()
{
	return _vy;
}

