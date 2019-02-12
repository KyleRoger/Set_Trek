#include "GameController.h"
#include "Graphics.h"
#include "Level1.h"

void Level1::Load()
{
	y = 0.0f;
	y = ySpeed = 0.0f;
	background = new SpriteSheet(L"Images\\SectorBackground.bmp", gfx); //This is where we can specify our file system object!
	planet1 = new SpriteSheet(L"Images\\Planet1.bmp", gfx);
	planet2 = new SpriteSheet(L"Images\\Planet2.bmp", gfx);
	planet3 = new SpriteSheet(L"Images\\Planet3.bmp", gfx);

	// Creating the Starship objects
	shipDetails = new Starship(gfx, 0, 384);
	shipBase = new Starship(gfx, 0, 384);

	shipBase->ChromaEffect(0.0f, 1.0f, 0.0f);
	shipDetails->ChromaEffect(0.0f, 1.0f, 0.0f);
}


void Level1::Unload()
{
	delete background;
}


void Level1::Update()
{
	ySpeed += 1.0f;
	y += ySpeed;
	if (y > 600)
	{
		y = 600; //keep the ball from dropping below the screen
		ySpeed = -30.0f; //What does this do?
	}
}

void Level1::Render()
{
	gfx->ClearScreen(0.0f, 0.0f, 0.5f);
	background->Draw();

}

