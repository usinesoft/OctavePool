#pragma once
#include "Ball.h"
#include "Rectangle.h"

enum Collision
{
	None,
	Up,
	Down,
	Left,
	Right
};

class Table:public Rectangle
{
	sf::Texture _tableImage;

public:
	Collision checkCollision(Ball ball) const;
	Table(float x, float y, float width, float height);

	std::shared_ptr<sf::Shape> getShape() const;

};

