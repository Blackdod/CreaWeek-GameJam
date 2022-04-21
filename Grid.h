#pragma once
#include <vector>
#include "Tile.h"


class Grid
{
public:
	Grid(int* indexes, Tile* tiles);
	void Draw() const;
private:
	const int m_Size;
	const int m_TileSize;
	int* m_pArray;
	Tile* m_pTiles;
};

