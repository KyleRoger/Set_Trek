

#include "Movement.h"


/**
* \brief Basic constructor for the Movement class.
* \details All the private data members are set to a safe value.
* \parm Nothing
* \return Nothing
*/

Movement::Movement(float width, float height)
{

	currentPositionPS = 50;      //current position of player ship
	windowWidth = width;
	windowHeight = height;
}


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


//Name: PlayerMove
//Purpose: The purpose of this method is to move the ship
//			to the next set square on the grid. If the ship
//			has reached the end of the screen, it will be 
//			reset to start at the front again.
void Movement::PlayerMove()
{

	int playerPosition = 0; //Storing the players position
	playerPosition = GetCurrentPositionPS();//Accessing position
	

	if (playerPosition == 59) //End of screen position.
	{
		playerPosition = 50; //Reset to start of screen.
		SetCurrentPositionPS(playerPosition); //Set new position
	}
	else
	{
		playerPosition += 1; //Increase player position.
		SetCurrentPositionPS(playerPosition); //Set the position
	}
}


int Movement::GetCurrentPositionPS()
{
	return currentPositionPS;

}

void Movement::SetCurrentPositionPS(int playerShipPosition)
{
	currentPositionPS = playerShipPosition;
}