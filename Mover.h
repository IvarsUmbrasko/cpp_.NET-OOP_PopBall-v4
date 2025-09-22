#pragma once
#include "Manager.h"

class Mover : public PopObject
{
protected:
	float _x, _y, _dX, _dY, _lastDX, _lastDY;
	int _color;
	int _borderColor;
	int _size;
	int _frameWidth, _frameHeight;
public:
	void setPos(float x, float y);
	void setColor(int color, int borderColor);
	int getSize();
	float getX();
	float getY();
	void reverseRotation();
	float getdX();
	float getdY();
	void setSpeed(float dX, float dY);
	void move();
	void interact(PopObject* popObject, bool isExtentionEnable);
	float getLastdX();
	float getLastdY();
	Mover(float frameWidth, float frameHeight, float x, float y);
};

