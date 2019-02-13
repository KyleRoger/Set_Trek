#pragma once
#include <Windows.h>
#include <vector>
#include <time.h>
#include <wincodec.h>
#include "Graphics.h"
#include "SpriteSheet.h"
#include "GameLevel.h"
#include <d2d1_1.h>
#include <d2d1_1helper.h>
#include <d3d11_1.h>
#include <d2d1effects_2.h>
#include <d2d1effecthelpers.h>
using namespace std;

class Starship
{
private:

	Graphics* gfx; //Reference to the Graphics class
	ID2D1Bitmap* bmp; //This will hold our loaded and converted Bitmap file
	ID2D1Effect* effect;
	SpriteSheet* image;


	float shipAngle;
	float energyLevel;

	bool isDead;
	bool isShooting;

public:

	Starship(Graphics* gfx, float startPosX, float startPosY);
	~Starship();

	void InitImage(const wchar_t* filename);
	void ChromaEffect(float r, float g, float b);

	void Draw(float left, float top);

};