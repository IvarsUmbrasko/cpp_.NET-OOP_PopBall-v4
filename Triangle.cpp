#include "Triangle.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>

using namespace System;
using namespace System::Drawing;


Triangle::Triangle(float frameWidth, float frameHeight, float x, float y, float dAlpha) : Rotator(frameWidth, frameHeight, x, y) {
	_x = x;
	_y = y;
	_size = 40;
	_color = Color::FromArgb(rand() % 256, rand() % 256, rand() % 256).ToArgb();
	_alpha = 0;
	_dAlpha = 0.1f;
	_frameWidth = frameWidth;
	_frameHeight = frameHeight;
	do {
		_dX = (rand() % 21) - 10;
		_dY = (rand() % 21) - 10;
	} while (_dX == 0 && _dY == 0);
}

void Triangle::draw(Graphics^ graphics) {
	SolidBrush brush(Color::FromArgb(_color));
	array<Point>^ points = gcnew array<Point>(3);

	for (int i = 0; i < 3; i++) {
		points[i] = Point(
			(int)(_x + _size * cos(_alpha + 2 * M_PI / 3 * i)),
			(int)(_y + _size * sin(_alpha + 2 * M_PI / 3 * i))
		);
	}
	graphics->FillPolygon(% brush, points);
}

void Triangle::interact(PopObject* popObject, bool isExtentionEnable) {
	Mover::interact(popObject, isExtentionEnable);
	if (isExtentionEnable) {
		_color = Color::FromArgb(rand() % 256, rand() % 256, rand() % 256).ToArgb();
	}
}
