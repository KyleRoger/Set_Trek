
#include "Vector.h"

void Vector::XVectorLength(float a, float b)
{
	xVectorLen = a - b;
}

void Vector::YVectorLength(float a, float b)
{
	yVectorLen = a - b;
}

float Vector::GetXRatio() 
{
	return xRat;
}

float Vector::GetYRatio()
{
	return yRat;
}

float Vector::GetXVectorLength()
{
	return xVectorLen;
}

float Vector::GetYVectorLength()
{
	return yVectorLen;
}

float Vector::GetMagnitude()
{
	return vectorMagnitude;
}

void Vector::VectorMagnitude(float xVector, float yVector)
{
	vectorMagnitude = sqrt(xVector * xVector + yVector * yVector);
}
void Vector::FrameRatio(float xVector, float yVector)
{
	VectorMagnitude(xVectorLen, yVectorLen);

	if (vectorMagnitude != 0)
	{
		xRat = xVectorLen / vectorMagnitude;
		yRat = yVectorLen / vectorMagnitude;
	}
}