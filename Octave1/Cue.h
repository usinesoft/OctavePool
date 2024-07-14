#pragma once
#include <memory>

namespace sf
{
	class Shape;
}

class Cue
{
	float _xBall;
	float _yBall;
	float _lenght;
	float _alpha;
	float _vx;
	float _vy;

	void computeVxVy();

public:
	Cue(float xBall, float yBall);

	std::shared_ptr<sf::Shape> getShape() const;

	void rotateUp();
	void rotateDown();
	void stronger();
	void weaker();

	float get_vX();
	float get_vY();

};

