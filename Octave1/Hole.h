#pragma once
#include <SFML/Graphics/Shape.hpp>

#include "Ball.h"
#include "Circle.h"

class Hole:public Circle
{
public:
	Hole(float x, float y);
	bool ballInHole(Ball ball);

	std::shared_ptr<sf::Shape> getShape() const;
};

