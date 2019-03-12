#pragma once
#include "GameLevel.h"
#include "Starship.h"
#include "Grid.h"
#include "Movement.h"
#include <thread>
#include <chrono>



class Level1 : public GameLevel
{
	float windowWidth;
	float windowHeight;
	float gridWidth;
	float gridHeight;
	bool gameStart;

	Movement* moving = new Movement(windowWidth, windowHeight);
	SpriteSheet* background;
	SpriteSheet* planet1;
	SpriteSheet* planet2;
	SpriteSheet* planet3;
	SpriteSheet* shipBaseTest;
	Starship* shipBase;
	Starship*  shipDetails;
	Starship* enemyShip;
	Grid* newGrid;


public:
	void Load() override;
	void Unload() override;
	bool Update() override;
	void Render() override;
	float GetWindowWidth(void);
	float GetWindowHeight(void);
	void SetWindowWidth(float width);
	void SetWindowHeight(float height);
};
