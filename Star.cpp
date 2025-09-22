#include "Star.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>

using namespace System;
using namespace System::Drawing;


Star::Star(float frameWidth, float frameHeight, float x, float y) : Rotator(frameWidth, frameHeight, x, y) {
}

void Star::draw(Graphics^ graphics) {
	SolidBrush brush(Color::FromArgb(_color));
	array<Point>^ points = gcnew array<Point>(10);
	float outerRadius = _size;
	float innerRadius = _size / 2;

	for (int i = 0; i < 5; i++) {
		points[i * 2] = Point(
			(int)(_x + outerRadius * cos(_alpha + (2 * M_PI / 5) * i)),
			(int)(_y + outerRadius * sin(_alpha + (2 * M_PI / 5) * i))
		);
		points[i * 2 + 1] = Point(
			(int)(_x + innerRadius * cos(_alpha + (2 * M_PI / 5) * (i + 0.5))),
			(int)(_y + innerRadius * sin(_alpha + (2 * M_PI / 5) * (i + 0.5)))
		);
	}
	graphics->FillPolygon(% brush, points);
}

void Star::interact(PopObject* popObject, bool isExtentionEnable) {
	Mover::interact(popObject, isExtentionEnable);
	if (isExtentionEnable) {
		float speed = (0.05f + (rand() % 10)) / 50;
		if (_dAlpha > 0) _dAlpha = speed;
		else _dAlpha = -speed;
	}
}