#include "Rotator.h"
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <cstdlib>

Rotator::Rotator(float frameWidth, float frameHeight, float x, float y) : Mover(frameWidth, frameHeight, x, y) {
	_alpha = 0.0f;
	_dAlpha = 0.5f;
}

void Rotator::reverseRotation() {
	_dAlpha = -_dAlpha;
}

void Rotator::move() {
	Mover::move();
	_alpha += _dAlpha;

	if (_alpha >= 2 * M_PI) {
		_alpha -= 2 * M_PI;
	}

	else if (_alpha < 0) {
		_alpha += 2 * M_PI;
	}
}
