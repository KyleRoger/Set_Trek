

#include "Movement.h"


/**
* \brief Basic constructor for the Movement class.
* \details All the private data members are set to a safe value.
* \parm Nothing
* \return Nothing
*/

Movement::Movement(float width, float height)
{

	currentPositionPS= 50;      //current position of player ship
	windowWidth = width;
	windowHeight = height;
}

/**
* \brief Basic destructor for the Movement class.
* \details it will release the objects end of the game.
*/
Movement::~Movement()
{


}

//setter

void Movement::SetWindowWidth(float width)
{
	windowWidth = width;
}
//getter
float Movement::GetWindowWidth(void)
{

	return windowWidth;
}

void Movement::SetWindowHeight(float height)

{
	windowHeight = height;
}

float Movement::GetWindowHeight(void)
{

	return windowHeight;
}


/**
* \brief move the player ship.
* \details Calls upon a D2D1 method to specify the location of image file.
* \param: pair mouseP
*         pair endP
* \return Nothing
*/

void Movement::PlayerMove()
{

	int playerPosition = 0;
	playerPosition = GetCurrentPositionPS();
	

	if (playerPosition == 59)
	{
		playerPosition = 50;
		SetCurrentPositionPS(playerPosition);

	}
	
	else
	{
		playerPosition += 1;
		SetCurrentPositionPS(playerPosition);
	}
}


int Movement::GetCurrentPositionPS()
{
	return currentPositionPS;

}
/**
* \brief This method set value for current Position for player ship.
* \details This method set value for  current Position for player ship.
* \param pair FLOAT, FOLAT- playerShipPosition
* \return Nothing
*/
void Movement::SetCurrentPositionPS(int playerShipPosition)
{
	currentPositionPS = playerShipPosition;
}