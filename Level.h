#pragma once
#include "Grid.h"
#include "OAMTable.h"
#include "Tile.h"

class Level
{
public:
	Level();
	virtual ~Level() = default;
	Level(const Level& c) = delete;
	Level& operator=(const Level& rhs) = delete;
	Level(Level&& c) = delete;
	Level& operator=(Level&& rhs) = delete;

	virtual void Update(float elapsedSec) = 0;
	void Draw(unsigned char sprite[256][16], unsigned char backGround[256][16], 
		OAMEntry oam[40], unsigned char grid[1024], unsigned char x, unsigned char y) const;
	virtual bool HasReachedEnd() = 0;


private:

	OAMTable* m_Table;
	Tile* m_BackgroundTiles[256];
	Tile* m_SpriteTiles[256];
	int* m_Indexes[256];
	//Grid m_Grid;
};

