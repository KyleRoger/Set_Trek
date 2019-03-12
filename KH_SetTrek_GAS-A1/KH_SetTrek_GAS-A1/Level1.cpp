#include "GameController.h"
#include "Graphics.h"
#include "Level1.h"
#include "Mouse.h"

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
	enemyShip = new Starship(gfx);
	shipDetails->InitImage(L"Images\\ShipDetail.bmp");
	shipBase->InitImage(L"Images\\ShipBase.bmp");
	enemyShip->InitImage(L"Images\\EnemyShip.bmp");



	//Chroma Key the planets
	planet1->ApplyChromaEffect();
	planet2->ApplyChromaEffect();
planet3->ApplyChromaEffect();

//Apply the Chroma Key to the shipBase and shipDetails.
shipBase->ShipChromaKey(0.0f, 1.0f, 0.0f);
shipDetails->ShipChromaKey(0.0f, 1.0f, 0.0f);

shipBase->SetXCoordinate(0.0);
shipDetails->SetXCoordinate(0.0);
shipBase->SetYCoordinate(windowHeight / 2);
shipDetails->SetYCoordinate(windowHeight / 2);

enemyShip->SetXCoordinate(windowWidth - gridWidth);
enemyShip->SetYCoordinate(windowHeight / 2);

enemyShip->ShipChromaKey(0.0f, 0.0f, 1.0f);

//Move the player forward
//moving->PlayerMove();

//Create a grid, construct it, create random coordinates and randomize the planets.
newGrid = new Grid(windowWidth, windowHeight);
newGrid->ConstructGrid();
newGrid->CreateRandomCoordinates();
newGrid->PlanetRandomize(planet1, planet2, planet3);


}


void Level1::Unload()
{
	delete background;
	delete planet1;
	delete planet2;
	delete planet3;
	delete shipBase;
	delete shipDetails;
	delete enemyShip;
}

//Name: Update
//Purpose: The purpose of this method is to update the game state. This is repeatedly
//			called within the fame loop and moves the ship from one side of the screen
//			to the next. The thread sleeps for 0.5 seconds and then continues to 
//			update the game state, move the player and potenttially re-randomize
//			the planets.
bool Level1::Update()
{

	bool gameEnd = false;

	if (shipBase->GetXCoordinate() + gridWidth >= windowWidth)
	{
		NewSector();
		newGrid->CreateRandomCoordinates();
		shipBase->SetIsMoving(false);
		NewSector();
	}
	else
	{
		if (Mouse::mouseX > 0 && Mouse::mouseY > 0 && !(shipBase->GetIsMoving()))
		{
			SetShipDestination(Mouse::mouseX, Mouse::mouseY);
		}
		else if (shipBase->GetIsMoving())
		{
			SetShipPosition();

			if (shipBase->GetIsMoving())
			{
				SetEnemyDest();
				SetEnemyPos();
			}

			IsMoveFinished();
		}
	}

	return gameEnd;
}
void Level1::IsMoveFinished()
{
	if (fabs(shipBase->GetXCoordinate() - shipBase->GetXDest()) < 5 &&
		fabs(shipBase->GetYCoordinate() - shipBase->GetYDest() < 5))
	{
		shipBase->SetXCoordinate(shipBase->GetXDest());
		shipDetails->SetXCoordinate(shipDetails->GetXDest());
		shipBase->SetYCoordinate(shipBase->GetYDest());
		shipDetails->SetYCoordinate(shipDetails->GetYDest());

		shipBase->SetIsMoving(false);
		shipDetails->SetIsMoving(false);
	}
}
void Level1::SetShipPosition()
{
	shipBase->SetXCoordinate(shipBase->GetXCoordinate() + (shipBase->GetVector()->GetXRatio() * 5));
	shipDetails->SetXCoordinate(shipDetails->GetXCoordinate() + (shipDetails->GetVector()->GetXRatio() * 5));
	shipBase->SetYCoordinate(shipBase->GetYCoordinate() + (shipBase->GetVector()->GetYRatio() * 5));
	shipDetails->SetYCoordinate(shipDetails->GetYCoordinate() + (shipDetails->GetVector()->GetYRatio() * 5));
}

void Level1::SetEnemyPos(void)
{
	if (enemyShip->GetVector()->GetMagnitude() <= ((windowWidth / 20) * 4) ||
		enemyShip->GetVector()->GetMagnitude() <= ((windowHeight / 20) * 4))
	{
		enemyShip->SetXCoordinate(enemyShip->GetXCoordinate() + (enemyShip->GetVector()->GetXRatio() * 5.15));
		enemyShip->SetYCoordinate(enemyShip->GetYCoordinate() + (enemyShip->GetVector()->GetYRatio() * 5.15));
	}
	else
	{
		enemyShip->SetXCoordinate(enemyShip->GetXCoordinate() + (enemyShip->GetVector()->GetXRatio() * 4));
		enemyShip->SetYCoordinate(enemyShip->GetYCoordinate() + (enemyShip->GetVector()->GetYRatio() * 4));
	}
}

void Level1::SetEnemyDest(void)
{
	enemyShip->SetXDest(shipBase->GetXCoordinate());
	enemyShip->SetYDest(shipBase->GetYCoordinate());

	enemyShip->GetVector()->XVectorLength(shipBase->GetXCoordinate(), enemyShip->GetXCoordinate());
	enemyShip->GetVector()->YVectorLength(shipBase->GetYCoordinate(), enemyShip->GetYCoordinate());

	enemyShip->GetVector()->FrameRatio(enemyShip->GetVector()->GetXVectorLength(), enemyShip->GetVector()->GetYVectorLength());
}

void Level1::ShipCollision(void)
{

}

void Level1::PlanetTouched(void)
{

}

void Level1::NewSector(void)
{

}

void Level1::SetShipDestination(float x, float y)
{
	shipBase->SetXDest(x - (gridWidth / 2));
	shipDetails->SetXDest(x - (gridWidth / 2));
	shipBase->SetYDest(y - (gridHeight / 2));
	shipDetails->SetYDest(y - (gridHeight / 2));

	shipBase->GetVector()->XVectorLength(shipBase->GetXDest(), shipBase->GetXCoordinate());
	shipDetails->GetVector()->XVectorLength(shipDetails->GetXDest(), shipDetails->GetXCoordinate());
	shipBase->GetVector()->YVectorLength(shipBase->GetYDest(), shipBase->GetYCoordinate());
	shipDetails->GetVector()->YVectorLength(shipDetails->GetYDest(), shipDetails->GetYCoordinate());

	shipBase->GetVector()->FrameRatio(shipBase->GetVector()->GetXVectorLength(), shipBase->GetVector()->GetYVectorLength());
	shipDetails->GetVector()->FrameRatio(shipDetails->GetVector()->GetXVectorLength(), shipDetails->GetVector()->GetYVectorLength());

	shipBase->SetOrientation();
	shipDetails->SetOrientation();

	shipBase->SetIsMoving(true);
	shipDetails->SetIsMoving(true);
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

	newGrid->PlanetRandomize(planet1, planet2, planet3);
	shipBase->Draw(shipBase->GetXCoordinate(), shipBase->GetYCoordinate(), shipBase->GetOrientation());
	shipDetails->Draw(shipDetails->GetXCoordinate(), shipDetails->GetYCoordinate(),shipDetails->GetOrientation());

	enemyShip->Draw(enemyShip->GetXCoordinate(),enemyShip->GetYCoordinate(),0);

}

