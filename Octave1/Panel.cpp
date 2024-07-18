#include "Panel.h"

Panel::Panel():Rectangle(150, 150, 300, 123)
{
	_panelImage.loadFromFile("tot01.png");
}

std::shared_ptr<sf::Shape> Panel::getShape() const
{
	sf::RectangleShape* pRectangle = new sf::RectangleShape();

	pRectangle->setSize(sf::Vector2f(300, 123));
	pRectangle->setPosition(150, 150);
	
	pRectangle->setTexture(&_panelImage);

	return std::shared_ptr<sf::Shape>(pRectangle);
}
