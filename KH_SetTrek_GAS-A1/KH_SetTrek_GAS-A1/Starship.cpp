
#include "Starship.h"
#include <d2d1_1.h>

Starship::Starship(Graphics* graphics)
{
	// Get a reference to the Graphics class
	gfx = graphics;

	// Initialize other data members to default values
	bmp = nullptr;
	chromaKeyEffect = nullptr;
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

//Name: ShipChromakey
//Purpose: To chroma out the green screen background. Takes in the
//			RGB values to know what to take out.
void Starship::ShipChromaKey(float r, float g, float b)
{
	gfx->GetDeviceContext()->CreateEffect(CLSID_D2D1ChromaKey, &chromaKeyEffect);
	bmp = image->GetBitmap();
	chromaKeyEffect->SetInput(0, bmp);
	chromaKeyEffect->SetValue(D2D1_CHROMAKEY_PROP_COLOR, D2D1::Vector3F(r, g, b));
	chromaKeyEffect->SetValue(D2D1_CHROMAKEY_PROP_TOLERANCE, 0.2f);
	chromaKeyEffect->SetValue(D2D1_CHROMAKEY_PROP_INVERT_ALPHA, false);
	chromaKeyEffect->SetValue(D2D1_CHROMAKEY_PROP_FEATHER, false);
}

void Starship::Draw(float left, float top)
{

	gfx->GetDeviceContext()->DrawImage(chromaKeyEffect,
		D2D1::Point2F(left, top));
	
}
