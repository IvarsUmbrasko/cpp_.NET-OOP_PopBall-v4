#include "Rectangle.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>

using namespace System;
using namespace System::Drawing;

MyRectangle::MyRectangle(float frameWidth, float frameHeight, float x, float y) : Rotator(frameWidth, frameHeight, x, y) {
}

void MyRectangle::draw(Graphics ^ graphics) {
    SolidBrush brush(Color::FromArgb(_color));
    Point topLeft(_x - _size / 2, _y - _size / 2);  
    int sideLength = _size;  
    array<Point>^ points = gcnew array<Point>(4);
    for (int i = 0; i < 4; i++) {
        points[i] = Point(
            (int)(_x + (sideLength / 2) * cos(_alpha + i * M_PI / 2)),
            (int)(_y + (sideLength / 2) * sin(_alpha + i * M_PI / 2))
        );
    }
    graphics->FillPolygon(% brush, points);  
}

void MyRectangle::interact(PopObject* popObject, bool isExtentionEnable) {
    Mover::interact(popObject, isExtentionEnable);
    if(isExtentionEnable) {
    _size = 20 + rand() % 60;
    }
}
