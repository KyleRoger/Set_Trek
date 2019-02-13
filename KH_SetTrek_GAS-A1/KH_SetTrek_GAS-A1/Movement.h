#pragma once
#include <Windows.h>
#include "Grid.h"
#include "Graphics.h"
using namespace std;

class Movement
{
private:

	float windowWidth;
	float windowHeight;
	float gridWidth;
	float gridHeight;

	int currentPositionPS;      //get the current position of player ship


public:

	Movement(float windowWidth, float windowHeight);

	~Movement(void);


	void SetWindowWidth(float width);
	void SetWindowHeight(float height);
	int GetCurrentPositionPS();
	Grid* moveGrid;
	Grid* planetGrid = new Grid(windowWidth, windowHeight);


	void SetCurrentPositionPS(int playerShipPosition);

	void PlayerMove(void);

	//-Getters
	float GetWindowWidth(void);
	float GetWindowHeight(void);
};