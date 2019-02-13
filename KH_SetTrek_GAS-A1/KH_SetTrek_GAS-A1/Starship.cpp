
#include "Starship.h"
#include <d2d1_1.h>

Starship::Starship(Graphics* graphics, float startPosX, float startPosY)
{
	// Get a reference to the Graphics class
	gfx = graphics;

	// Initialize other data members to default values
	bmp = nullptr;
	effect = nullptr;
	image = nullptr;
}


Starship::~Starship()
{
	if (image)
	{
		delete image;
		image = nullptr;
	}
}


void Starship::InitImage(const wchar_t* filename)
{
	image = new SpriteSheet(filename, gfx);
}

void Starship::ChromaEffect(float r, float g, float b)
{
	gfx->GetDeviceContext()->CreateEffect(CLSID_D2D1ChromaKey, &effect);

	// Get the bitmap resource from UploadImage
	bmp = image->GetBitmap();

	effect->SetInput(0, bmp);
	effect->SetValue(D2D1_CHROMAKEY_PROP_COLOR, D2D1::Vector3F(r, g, b));
	effect->SetValue(D2D1_CHROMAKEY_PROP_TOLERANCE, 0.2f);
	effect->SetValue(D2D1_CHROMAKEY_PROP_INVERT_ALPHA, false);
	effect->SetValue(D2D1_CHROMAKEY_PROP_FEATHER, false);
}

void Starship::Draw(float left, float top)
{

	gfx->GetDeviceContext()->DrawImage(effect,
		D2D1::Point2F(left, top));
	//gfx->GetDeviceContext()->DrawImage(
	//	effect,
	//	D2D1::Point2F(left, top),
	//	D2D1::RectF(0, 0, gfx->GetWindowWidth(), gfx->GetWindowHeight())
	//);
}
