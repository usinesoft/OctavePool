#include "Rectangle.h"

#include <SFML/Graphics.hpp>

#pragma once

class Panel:Rectangle
{

	sf::Texture _panelImage;

public:
	
	Panel();

	std::shared_ptr<sf::Shape> getShape() const;

};

