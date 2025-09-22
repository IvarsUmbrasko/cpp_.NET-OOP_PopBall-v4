#include "Ball.h"
#include <math.h>
#include <cstdlib>

using namespace System;
using namespace System::Drawing;

Ball::Ball(int frameWidth, int frameHeight, float x, float y) : Mover(frameWidth, frameHeight, x, y) {

}

void Ball::draw(Graphics^ graphics) {
	SolidBrush brush(Color::FromArgb(_color));
	Pen pen(Color::FromArgb(_borderColor), 4);
	graphics->FillEllipse(% brush, (int)(_x - _size / 2), (int)(_y - _size / 2), _size, _size);
	graphics->DrawEllipse(% pen, (int)(_x - _size / 2), (int)(_y - _size / 2), _size, _size);
}

void Ball::move(bool isExtentionEnable) {
	Mover::move();
	if (isExtentionEnable) {
		_dX *= 0.99;
		_dY *= 0.99;
		if (fabs(_dX) < 0.1f) _dX = 0;
		if (fabs(_dY) < 0.1f) _dY = 0;
	}
}

void Ball::interact(PopObject* popObject, bool isExtentionEnable) {
	Mover::interact(popObject, isExtentionEnable);
	if (_dX == 0 && _dY == 0 && isExtentionEnable) {
		float angle = rand() % 360;
		float speed = 1 + rand() % 10;
		_dX = speed * cos(angle);
		_dY = speed * sin(angle);
	}
}