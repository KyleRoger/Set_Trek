#pragma once

#include <wincodec.h> //This is the WIC codec header - we need this to decode image files
#include "Graphics.h" //This includes both Windows and D2D libraries

class SpriteSheet
{
	Graphics* gfx; //Reference to the Graphics class
	ID2D1Bitmap* bmp; //This will hold our loaded and converted Bitmap file


public:
	//Constructor
	SpriteSheet(const wchar_t* filename, Graphics* gfx);

	//Destructor
	~SpriteSheet();

	//Draw bitmap to the render target
	void DrawBackground(float right, float bottom);
	void Draw();
	void DrawPlanet(float left, float top);
	void ApplyChromaEffect();
	ID2D1Bitmap* GetBitmap(void);
	void DrawMiniGame(float width, float height);

};