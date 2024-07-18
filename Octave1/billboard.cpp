#include "billboard.h"
billboard::billboard(float x, float y, float width, float height) :Rectangle(x, y, width, height)
{
	_tot01Image.loadFromFile("tot01.png");

}


std::shared_ptr <sf::Shape> Table::getShape() const
{

	sf::RectangleShape* pRectangle = new sf::RectangleShape();

	pRectangle->setSize(sf::Vector2f(_width, _height));
	pRectangle->setPosition(_x, _y);
	pRectangle->setFillColor(sf::Color(10, 200, 10));
	pRectangle->setTexture(&_tot01Image);

	return std::shared_ptr<sf::Shape>(pRectangle);

}