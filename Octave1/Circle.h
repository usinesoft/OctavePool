#pragma once
class Circle
{
protected:

	float _x=0;
	float _y=0;
	float _radius=1;

public:
	Circle(float x, float y, float radius );

	void moveTo(float x, float y);
	void display ();
	void move(float dX, float dY);
	float distanceToCenter(Circle otherCircle) const;
	
	float minimumDistance(Circle otherCircle) const;
};

