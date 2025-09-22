#include "Mover.h"
#include "math.h"
#include <cstdlib>


Mover::Mover(float frameWidth, float frameHeight, float x, float y) {
	_x = x;
	_y = y;
	_size = 40;
	_color = Color::FromArgb(rand() % 256, rand() % 256, rand() % 256).ToArgb();
	_borderColor = Color::FromArgb(rand() % 256, rand() % 256, rand() % 256).ToArgb();
	_frameWidth = frameWidth;
	_frameHeight = frameHeight;
	do {
		_dX = (rand() % 21) - 10;
		_dY = (rand() % 21) - 10;
	} while (_dX == 0 && _dY == 0);
}

void Mover::setPos(float x, float y) {
	if (_size / 2 > x) x = _size / 2;
	if (x > _frameWidth - _size / 2) x = _frameWidth - _size / 2;
	if (_size / 2 > y) y = _size / 2;
	if (y > _frameHeight - _size / 2) y = _frameHeight - _size / 2;

	_x = x;
	_y = y;
}

void Mover::setColor(int color, int borderColor) {
	_color = color;
	_borderColor = borderColor;
}

void Mover::reverseRotation() {}

int Mover::getSize() {
	return _size / 2;
}

float Mover::getX() {
	return _x;
}

float Mover::getY() {
	return _y;
}

float Mover::getdX() {
	return _dX;
}

float Mover::getdY() {
	return _dY;
}

void Mover::setSpeed(float dX, float dY) {
	float speed = sqrt(dX * dX + dY * dY);
	float angle = atan2(dY, dX);

	if (speed < 50 && speed > 1) {
		_dX = speed * cos(angle);
		_dY = speed * sin(angle);
		_lastDX = _dX;
		_lastDY = _dY;
	}

	if (fabs(speed) < 1) { speed = 0; _dX = 0, _dY = 0; }
}

void Mover::move() {
	_x += getdX();
	_y += getdY();

	if (_x - _size / 2 < 0 || _x + _size / 2 > _frameWidth) {
		_dX = -_dX;
		_x += _dX;
		reverseRotation();
	}
	if (_y - _size / 2 < 0 || _y + _size / 2 > _frameHeight) {
		_dY = -_dY;
		_y += _dY;
		reverseRotation();
	}
}

void Mover::interact(PopObject* popObject, bool isExtentionEnable) {
	_dX = -_dX;
	_dY = -_dY;
}

float Mover::getLastdX() {
	return _lastDX;
}

float Mover::getLastdY() {
	return _lastDY;
}
