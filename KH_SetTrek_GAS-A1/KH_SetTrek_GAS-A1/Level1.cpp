#include "GameController.h"
#include "Graphics.h"
#include "Grid.h"
#include "Level1.h"

void Level1::Load()
{

	windowWidth = gfx->GetWindowWidth();
	windowHeight = gfx->GetWindowHeight();
	gridWidth = windowWidth / 10;
	gridHeight = windowHeight / 10;

	y = 0.0f;
	y = ySpeed = 0.0f;
	background = new SpriteSheet(L"Images\\SectorBackground.bmp", gfx); //This is where we can specify our file system object!
	planet1 = new SpriteSheet(L"Images\\Planet1.bmp", gfx);
	planet2 = new SpriteSheet(L"Images\\Planet2.bmp", gfx);
	planet3 = new SpriteSheet(L"Images\\Planet3.bmp", gfx);
	//shipBaseTest = new SpriteSheet(L"Images\\shipBase.bmp", gfx);

	// Creating the Starship objects
	shipDetails = new Starship(gfx, 0, 384);
	shipBase = new Starship(gfx, 0, 384);
	// Loading the image resources
	shipDetails->InitImage(L"Images\\ShipDetail.bmp");
	shipBase->InitImage(L"Images\\ShipBase.bmp");

	planet1->ApplyChromaEffect();
	planet2->ApplyChromaEffect();
	planet3->ApplyChromaEffect();
	//shipBaseTest->ApplyChromaEffect();

	shipBase->ChromaEffect(0.0f, 1.0f, 0.0f);
	shipDetails->ChromaEffect(0.0f, 1.0f, 0.0f);

	moving->PlayerMove();

	newGrid = new Grid(windowWidth,windowHeight);
	newGrid->ConstructGrid();
	newGrid->GenerateRandCoord();
	newGrid->PlanetStore();

}


void Level1::Unload()
{
	delete background;
	delete planet1;
	delete planet2;
	delete planet3;
	delete shipBase;
	delete shipDetails;
}


void Level1::Update()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	moving->PlayerMove();
	int position = moving->GetCurrentPositionPS();
	if (position == 50)
	{
		newGrid->GenerateRandCoord();
		newGrid->PlanetStore();
	}

}

float Level1::GetWindowWidth(void)
{
	return windowWidth;
}
float Level1::GetWindowHeight(void)
{
	return windowHeight;
}
/**
* \brief This method set value for window width.
* \details This method set value for window width.
* \param FLOAT- width
* \return Nothing
*/
void Level1::SetWindowWidth(float width)
{
	windowWidth = width;

}
/**
* \brief This method set value for window height.
* \details This method set value for window height.
* \param FLOAT- height
* \return Nothing
*/
void Level1::SetWindowHeight(float height)
{
	windowHeight = height;
}


void Level1::Render()
{
	gfx->ClearScreen(0.0f, 0.0f, 0.5f);
	background->DrawBackground(0, 0, windowWidth, windowHeight);

	for (int i = 0; i < newGrid->randGrid.size(); i++)
	{

		if (newGrid->gplCombination[i].second == 1)
		{
			planet1->DrawPlanet(newGrid->randGrid[i].first, newGrid->randGrid[i].second);
		}
		if (newGrid->gplCombination[i].second == 2)
		{
			planet2->DrawPlanet(newGrid->randGrid[i].first, newGrid->randGrid[i].second);
		}
		if (newGrid->gplCombination[i].second == 3)
		{
			planet3->DrawPlanet(newGrid->randGrid[i].first, newGrid->randGrid[i].second);
		}
	}
	//shipBaseTest->Draw();
	shipBase->Draw(newGrid->grid[moving->GetCurrentPositionPS()].first, newGrid->grid[moving->GetCurrentPositionPS()].second);
	shipDetails->Draw(newGrid->grid[moving->GetCurrentPositionPS()].first, newGrid->grid[moving->GetCurrentPositionPS()].second);


}

