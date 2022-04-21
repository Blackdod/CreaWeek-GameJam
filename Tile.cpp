#include "pch.h"
#include "Tile.h"
#include "utils.h"
#include <iostream>

const int Tile::m_Divide{ 255 };

const Color4f Tile::m_DarkestGreen{ 15.f / m_Divide,56.f / m_Divide,15.f / m_Divide,1.f };
const Color4f Tile::m_DarkGreen{ 48.f / m_Divide,98.f / m_Divide,48.f / m_Divide,1.f };
const Color4f Tile::m_LightGreen{ 139.f / m_Divide,172.f / m_Divide,15.f / m_Divide,1.f };
const Color4f Tile::m_LightestGreen{ 155.f / m_Divide,188.f / m_Divide,15.f / m_Divide,1.f };


Tile::Tile(unsigned char tile[16])
	:m_Scale{ 4.f },
	m_PixelWidth{ m_Scale },
	m_PixelHeight{ m_Scale },
	m_NrRows{ 8 },
	m_NrColumns{ 8 }
{
	for (int i = 0; i < m_NrHex; i++)
	{
		m_TileLabel[i] = tile[i];
	}
}

void Tile::Draw() const
{	
	Point2f leftBottom{ 0.f,float(m_PixelHeight * m_NrRows) };

	for (size_t idx1 = 0; idx1 < 16; idx1 += 2)
	{
	Color4f colors[8];

	int bit[8];

	bit[0] = m_TileLabel[idx1] & 0b00000001;
	bit[1] = m_TileLabel[idx1] & 0b00000010;
	bit[2] = m_TileLabel[idx1] & 0b00000100;
	bit[3] = m_TileLabel[idx1] & 0b00001000;
	bit[4] = m_TileLabel[idx1] & 0b00010000;
	bit[5] = m_TileLabel[idx1] & 0b00100000;
	bit[6] = m_TileLabel[idx1] & 0b01000000;
	bit[7] = m_TileLabel[idx1] & 0b10000000;

	int bit2[8];

	bit2[0] = m_TileLabel[idx1 + 1] & 0b00000001;
	bit2[1] = m_TileLabel[idx1 + 1] & 0b00000010;
	bit2[2] = m_TileLabel[idx1 + 1] & 0b00000100;
	bit2[3] = m_TileLabel[idx1 + 1] & 0b00001000;
	bit2[4] = m_TileLabel[idx1 + 1] & 0b00010000;
	bit2[5] = m_TileLabel[idx1 + 1] & 0b00100000;
	bit2[6] = m_TileLabel[idx1 + 1] & 0b01000000;
	bit2[7] = m_TileLabel[idx1 + 1] & 0b10000000;

	for (size_t i = 0; i < 8; i++)
	{

		if (bit[i] > 0 && bit2[i] > 0)
		{
			colors[i] = m_DarkestGreen;
			//zwart
		}
		else if (bit[i] > 0 && bit2[i] == 0)
		{
			colors[i] = m_DarkGreen;
			//donker grijs
		}
		else if (bit[i] == 0 && bit2[i] > 0)
		{
			//licht grijs
			colors[i] = m_LightGreen;

		}
		else
		{
			colors[i] = Color4f{ 0.0f,0.0f,0.0f,0.0f };
			//wit
		}
	}

	for (size_t i = 0; i < m_NrColumns; i++)
	{
		utils::SetColor(colors[i]);
		utils::FillRect(leftBottom, m_PixelWidth, m_PixelHeight);
		leftBottom.x += m_PixelWidth;
	}

	leftBottom.x = 0.f;
	leftBottom.y -= m_PixelHeight;

	}
}
