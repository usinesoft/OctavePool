#include "Table.h"

#include <ios>

Collision Table::checkCollision(Ball ball) const
{
	if(ball.isCollisionX(_x))
		return Collision::Left;

	if(ball.isCollisionX(_x+_width))
		return Collision::Right;

	if(ball.isCollisionY(_y+_height))
		return Collision::Up;

	if(ball.isCollisionY(_y))
		return Collision::Down;

	return Collision::None;

}

Table::Table(float x, float y, float width, float height):Rectangle(x, y, width, height)
{
}

std::shared_ptr<sf::Shape> Table::getShape() const
{

	sf::RectangleShape * pRectangle = new sf::RectangleShape();

	pRectangle-> setSize(sf::Vector2f(_width, _height));
	pRectangle-> setPosition(_x, _y);
	pRectangle-> setFillColor(sf::Color(10, 200, 10));

	return std::shared_ptr<sf::Shape>(pRectangle);

}


