#pragma once
#include "Rotator.h"

using namespace System::Drawing;


class MyRectangle : public Rotator
{
public:
	void draw(Graphics^ graphics);
	void interact(PopObject* popObject, bool isExtentionEnable);
	MyRectangle(float frameWidth, float frameHeight, float x, float y);
};

