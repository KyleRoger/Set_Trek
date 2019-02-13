
#include "Grid.h"


/**
* \brief The default Grid constructor.
* \param None
* \return None
*/
Grid::Grid(void)
{
	windowWidth = 0.0f;
	windowHeight = 0.0f;
	gridWidth = 0.0f;
	gridHeight = 0.0f;

	numOfRows = 0;
	numOfCols = 0;
}


/**
* \brief A Grid constructor taking 2 parameters.
* \details The 2 parameters are floats for window sizes.
* \param width - float - The width of the window
* \param height - float - The height of the window
* \return None
*/
Grid::Grid(float width, float height)
{
	windowWidth = width;
	windowHeight = height;
	gridWidth = windowWidth / kNumberOfGrid;
	gridHeight = windowHeight / kNumberOfGrid;

	numOfRows = 0;
	numOfCols = 0;
}


/**
* \brief Destructor for the Grid object.
*/
Grid::~Grid(void)
{
}


/**
* \brief Construct the space grid.
* \details The calculation for the space grids are
*       found by each row and column. Initially the an
*       individual grid with and grid height is found.
*/
void Grid::ConstructGrid(void)
{
	int row = 0;
	int col = 0;

	for (row = 0; row < kNumberOfGrid; ++row)
	{
		for (col = 0; col < kNumberOfGrid; ++col)
		{
			coordinates.first = col * gridWidth;
			coordinates.second = row * gridHeight;
			grid.push_back(coordinates);
		}
	}
}
/**
* \brief Generate random coordinates for Planet spawning.
* \details The grid points are chosen at random. There is an
*       approximately 5% chance that a Planet will spawn at the grid point.
*/
void Grid::GenerateRandCoord(void)
{
	srand((unsigned)time(NULL));
	bool isSpawn = false;
	randGrid.clear();

	// For each grid position, calculate the chance
	// for a planet to spawn. There is a 1 in 20 (5%) chance
	// that a planet will spawn...
	for (int i = 0; i < grid.size(); ++i)
	{

			isSpawn = (rand() % 100) < kPlanetSpawnChance;

			if (isSpawn)
			{
				// These are the chosen grid positions 
				// where a planet is going to be drawn at
				coordinates.first = grid[i].first;
				coordinates.second = grid[i].second;
				randGrid.push_back(coordinates);

				isSpawn = false;
			}
	}
}

/**
* \brief This method place all planet to a vector and place grid value and planet to another vector.
* \details This method place all planet to a vector and and randomly picked planet and  corronsponding grid values
* \ in a vector that cah have a planet.
* \param Nothing
* \return Nothing
*/
void Grid::PlanetStore()
{
	srand((unsigned)time(NULL));
	int randomPlanet = 0;


	int index = 0;;
	for (index = 0; index < randGrid.size(); index++)
	{
		randomPlanet = (rand() % 3 + 1);

		gridPlanet.first = index;
		gridPlanet.second = randomPlanet;//randomPlanet;
		gplCombination.push_back(gridPlanet);
	}
}

//-Accessors
float Grid::GetWindowWidth(void) const {
	return windowWidth;
}
float Grid::GetWindowHeight(void) const {
	return windowHeight;
}

float Grid::GetWidth(void) const {
	return gridWidth;
}
float Grid::GetHeight(void) const {
	return gridHeight;
}

int Grid::GetNumRows(void) const {
	return numOfRows;
}
int Grid::GetNumCols(void) const {
	return numOfCols;
}

int Grid::GetGridNum(void) const {
	return (int)grid.size();
}
int Grid::GetRandCoordSize(void) const {
	return (int)randGrid.size();
}

vector<pair<float, float>> Grid::GetGrid(void) const {
	return grid;
}
vector<pair<float, float>> Grid::GetRandCoord(void) const {
	return randGrid;
}