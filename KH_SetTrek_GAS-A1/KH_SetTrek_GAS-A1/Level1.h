#pragma once
#include "GameLevel.h"
#include "Starship.h"


class Level1 : public GameLevel
{
	float y;
	float ySpeed;
	SpriteSheet* background;
	SpriteSheet* planet1;
	SpriteSheet* planet2;
	SpriteSheet* planet3;
	Starship* shipBase;
	Starship*  shipDetails;

public:
	void Load() override;
	void Unload() override;
	void Update() override;
	void Render() override;

};
