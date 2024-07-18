#include "Hole.h"

using namespace std;

Hole::Hole(float x, float y): Circle(x, y, 20 )
{
	
}


shared_ptr<sf::Shape> Hole::getShape() const
{
	const auto shape = new sf::CircleShape(_radius);
	shape->setPosition(_x, _y);
	shape->setFillColor(sf::Color(10, 10, 10));
	

	return shared_ptr<sf::Shape>(shape);
}
bool Hole::ballInHole(Ball ball)
{
	float distance= distanceToCenter(ball);
	return distance<=10;
}
