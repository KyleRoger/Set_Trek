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

	//Create the objects with the images gicen in the assignement
	background = new SpriteSheet(L"Images\\SectorBackground.bmp", gfx); //This is where we can specify our file system object!
	planet1 = new SpriteSheet(L"Images\\Planet1.bmp", gfx);
	planet2 = new SpriteSheet(L"Images\\Planet2.bmp", gfx);
	planet3 = new SpriteSheet(L"Images\\Planet3.bmp", gfx);
	shipDetails = new Starship(gfx);
	shipBase = new Starship(gfx);
	shipDetails->InitImage(L"Images\\ShipDetail.bmp");
	shipBase->InitImage(L"Images\\ShipBase.bmp");

	//Chroma Key the planets
	planet1->ApplyChromaEffect();
	planet2->ApplyChromaEffect();
	planet3->ApplyChromaEffect();

	//Apply the Chroma Key to the shipBase and shipDetails.
	shipBase->ShipChromaKey(0.0f, 1.0f, 0.0f);
	shipDetails->ShipChromaKey(0.0f, 1.0f, 0.0f);

	//Move the player forward
	moving->PlayerMove();

	//Create a grid, construct it, create random coordinates and randomize the planets.
	newGrid = new Grid(windowWidth,windowHeight);
	newGrid->ConstructGrid();
	newGrid->CreateRandomCoordinates();
	newGrid->PlanetRandomize();

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

//Name: Update
//Purpose: The purpose of this method is to update the game state. This is repeatedly
//			called within the fame loop and moves the ship from one side of the screen
//			to the next. The thread sleeps for 0.5 seconds and then continues to 
//			update the game state, move the player and potenttially re-randomize
//			the planets.
void Level1::Update()
{
	//Sleep the program for half a second.
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	moving->PlayerMove(); //Move the player one step forward.
	int position = moving->GetCurrentPositionPS(); //Get player location.
	if (position == 50) //If the player position is at the start. Randomize planets.
	{
		newGrid->CreateRandomCoordinates(); //Generate a new set of coordinates
		newGrid->PlanetRandomize(); //Re-randomize which planet are placed on
									//above randomly generated coordinates.
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

void Level1::SetWindowWidth(float width)
{
	windowWidth = width;

}

void Level1::SetWindowHeight(float height)
{
	windowHeight = height;
}


void Level1::Render()
{
	gfx->ClearScreen(0.0f, 0.0f, 0.5f);
	background->DrawBackground(windowWidth, windowHeight);

	for (int i = 0; i < newGrid->selectCoord.size(); i++)
	{

		if (newGrid->PlanetLocations[i].second == 1)
		{
			planet1->DrawPlanet(newGrid->selectCoord[i].first, newGrid->selectCoord[i].second);
		}
		if (newGrid->PlanetLocations[i].second == 2)
		{
			planet2->DrawPlanet(newGrid->selectCoord[i].first, newGrid->selectCoord[i].second);
		}
		if (newGrid->PlanetLocations[i].second == 3)
		{
			planet3->DrawPlanet(newGrid->selectCoord[i].first, newGrid->selectCoord[i].second);
		}
	}

	shipBase->Draw(newGrid->grid[moving->GetCurrentPositionPS()].first, newGrid->grid[moving->GetCurrentPositionPS()].second);
	shipDetails->Draw(newGrid->grid[moving->GetCurrentPositionPS()].first, newGrid->grid[moving->GetCurrentPositionPS()].second);


}

