#include "Mouse.h"


float Mouse::mouseX;
float Mouse::mouseY;
float Mouse::EnergyLevel;

bool Mouse::IsClick;


void Mouse::Init(void)
{

	mouseX = 0.0;
	mouseY = 0.0;
	EnergyLevel = 1000;
	IsClick = false;
}

Mouse::Mouse(float x, float y, bool isClick)
{

	mouseX = x;
	mouseY = y;
	EnergyLevel = 1000;
	IsClick = isClick;
}