#pragma once
#include "Mover.h"

class Rotator : public Mover
{
protected:
	float _alpha, _dAlpha;
public:
	void move();
	void reverseRotation();
	Rotator(float frameWidth, float frameHeight, float x, float y);
};

