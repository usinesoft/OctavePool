#pragma once
#include "Circle.h"

#include <SFML/Graphics.hpp>

class Ball:public Circle
{
	
	double _vx = 0;
	double _vy = 0;

public:

	

	Ball(float x, float y);


	void shoot(float vx, float vy);
	void advance();

	bool isCollisionY (float yWall);

	bool isCollisionX (float xWall);

	void bounceY();
	void bounceX();

	std::shared_ptr<sf::Shape> getShape() const;
};

