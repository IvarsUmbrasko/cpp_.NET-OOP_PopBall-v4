#pragma once
#include "Rotator.h"

using namespace System::Drawing;

class Star : public Rotator
{
public:
	void draw(Graphics^ graphics);
	void interact(PopObject* popObject, bool isExtentionEnable);
	Star(float frameWidth, float frameHeight, float x, float y);
};

