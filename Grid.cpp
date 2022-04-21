#include "pch.h"
#include "Grid.h"

Grid::Grid(int* indexes, Tile* tiles):
	m_pArray{indexes},
	m_pTiles{tiles},
	m_Size{32*32},
	m_TileSize{256}
{
}

void Grid::Draw() const
{
	Point2f startPos{ 0,32 * 8 };
	int idx{};
	for (int rows = 0; rows < 32; rows++)
	{
		for (int cols = 0; cols < 32; cols++)
		{
			idx = rows * 32 + cols;
			m_pTiles[m_pArray[idx]].Draw();
			startPos.x += 32.0f;
		}
		startPos.x = 0;
		startPos.y -= 32;
	}
	
}
