#pragma once
#include "Rotator.h"

using namespace System::Drawing;

class Triangle : public Rotator
{
public:
	void draw(Graphics^ graphics);
	void interact(PopObject* popObject, bool isExtentionEnable);
	Triangle(float frameWidth, float frameHeight, float x, float y, float dAlpha);
};

