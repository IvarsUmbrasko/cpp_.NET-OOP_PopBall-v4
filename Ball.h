#pragma once
#include "Mover.h"

using namespace System::Drawing;

class Ball : public Mover
{
public:
	void draw(Graphics^ graphics);
	void move(bool isExtentionEnable);
	void interact(PopObject* popObject, bool isExtentionEnable);
	Ball(int frameWidth, int frameHeight, float x, float y);
};