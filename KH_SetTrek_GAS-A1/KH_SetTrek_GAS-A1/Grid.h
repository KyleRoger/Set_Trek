
#pragma once
#include <time.h>
#include <vector>
#include "Graphics.h"
using namespace std;



//===================
// CONSTANTS
//===================
#define kNumberOfGrid		10
#define kMaximumRow         (kNumberOfGrid)
#define kCenterGrid			49
#define kWindowPadding      1.0f

#define kPlanetPadding      5.0f
#define kPlanetSpawnChance  5

//=============================
// GRAPHIC STRUCT DEFINITIONS
//=============================

//===================
// CLASS
//===================
/**
* \class Grid
* \brief The Grid object has methods and functionalities to manipulate a grid.
* \details This grid is used within the game level. It allows for game objects
*	to be mapped to a defined point.
*/
class Grid
{
private:

	float windowWidth;				//!< The width of the window
	float windowHeight;				//!< The height of the window

	float gridWidth;				//!< The width of 1 grid
	float gridHeight;				//!< The height of 1 grid

	int numOfRows;					//!< The number of rows that comprises of the grid
	int numOfCols;					//!< The number of cols that comprises of the grid


public:

	pair<float, float> coordinates;
	pair< int, int> gridPlanet;
	vector<pair<float, float>> grid;			//!< Contains the absolute position for the 10 by 10 grid. There are 100 squares in total
	vector<pair<float, float>> randGrid;		//!< Contains the grid coordinates of where a random planet may spawn
	vector <pair <int, int>> gplCombination;  //strore picked grid value and corrosponding planet to place

	//-Constructors
	Grid(void);
	Grid(float windowWidth, float windowHeight);

	//-Destructors
	~Grid(void);

	//-Methods
	void ConstructGrid(void);
	void GenerateRandCoord(void);

	//-Accessors
	float GetWindowWidth(void) const;
	float GetWindowHeight(void) const;

	float GetWidth(void) const;
	float GetHeight(void) const;

	int GetNumRows(void) const;
	int GetNumCols(void) const;

	int GetGridNum(void) const;
	int GetRandCoordSize(void) const;

	vector<pair<float, float>> GetGrid(void) const;
	vector<pair<float, float>> GetRandCoord(void) const;
	void PlanetStore();
};