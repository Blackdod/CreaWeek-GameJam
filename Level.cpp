#include "pch.h"
#include "Level.h"
#include "utils.h"
#include "OAMEntry.h"

const int m_Divide{ 255 };

const Color4f m_DarkestGreen{ 15.f / m_Divide,56.f / m_Divide,15.f / m_Divide,1.f };
const Color4f m_DarkGreen{ 48.f / m_Divide,98.f / m_Divide,48.f / m_Divide,1.f };
const Color4f m_LightGreen{ 139.f / m_Divide,172.f / m_Divide,15.f / m_Divide,1.f };
const Color4f m_LightestGreen{ 155.f / m_Divide,188.f / m_Divide,15.f / m_Divide,1.f };
Level::Level()
{
	unsigned char TileLabel[] =
	{
	  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	  0x3C,0x3C,0x52,0x6E,0xD3,0xAD,0xD3,0xAD
	};

	for (int i{}; i < 256; ++i)
	{
		m_BackgroundTiles[i] = new Tile{ TileLabel };
		m_Indexes[i] = 0;
	}
	
	//Put all the indexes in the m_Indexes array
	//Put all the tiles in m_Tiles
	//m_Grid = new Grid{ m_Indexes,m_BackgroundTiles };
}


void DrawSprite(OAMEntry entry, unsigned char x, unsigned char y, unsigned char sprites[256][16])
{
	glPushMatrix();
	{
		Point2f pos{ entry.GetPosition() };
		pos.x += x;
		pos.y += y;
		glTranslatef(float(pos.x), float(pos.y), 0.f);
		glScalef((entry.GetFlipX() ? -1.f : 1.f), (entry.GetFlipY() ? -1.f : 1.f), 1.f);
		Point2f rightBottom{-32.f, float(4 * 8) };

		for (size_t idx1 = 0; idx1 < 16; idx1 += 2)
		{
			Color4f colors[8];

			int bit[8];

			bit[0] = sprites[entry.GetTileId()][idx1] & 0b00000001;
			bit[1] = sprites[entry.GetTileId()][idx1] & 0b00000010;
			bit[2] = sprites[entry.GetTileId()][idx1] & 0b00000100;
			bit[3] = sprites[entry.GetTileId()][idx1] & 0b00001000;
			bit[4] = sprites[entry.GetTileId()][idx1] & 0b00010000;
			bit[5] = sprites[entry.GetTileId()][idx1] & 0b00100000;
			bit[6] = sprites[entry.GetTileId()][idx1] & 0b01000000;
			bit[7] = sprites[entry.GetTileId()][idx1] & 0b10000000;

			int bit2[8];

			bit2[0] = sprites[entry.GetTileId()][idx1 + 1] & 0b00000001;
			bit2[1] = sprites[entry.GetTileId()][idx1 + 1] & 0b00000010;
			bit2[2] = sprites[entry.GetTileId()][idx1 + 1] & 0b00000100;
			bit2[3] = sprites[entry.GetTileId()][idx1 + 1] & 0b00001000;
			bit2[4] = sprites[entry.GetTileId()][idx1 + 1] & 0b00010000;
			bit2[5] = sprites[entry.GetTileId()][idx1 + 1] & 0b00100000;
			bit2[6] = sprites[entry.GetTileId()][idx1 + 1] & 0b01000000;
			bit2[7] = sprites[entry.GetTileId()][idx1 + 1] & 0b10000000;

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

			for (size_t i = 0; i < 8; i++)
			{
				utils::SetColor(colors[i]);
				utils::FillRect(rightBottom, 4, 4);
				rightBottom.x += 4;
			}

			rightBottom.x = 0.f;
			rightBottom.y -= 4;

		}
	}
	glPopMatrix();
}

void DrawTile(unsigned char tiles[256][16], unsigned char index)
{
	Point2f leftBottom{ 0.f,float(4 * 8) };

	for (size_t idx1 = 0; idx1 < 16; idx1 += 2)
	{
		Color4f colors[8];

		int bit[8];

		bit[0] = tiles[index][idx1] & 0b00000001;
		bit[1] = tiles[index][idx1] & 0b00000010;
		bit[2] = tiles[index][idx1] & 0b00000100;
		bit[3] = tiles[index][idx1] & 0b00001000;
		bit[4] = tiles[index][idx1] & 0b00010000;
		bit[5] = tiles[index][idx1] & 0b00100000;
		bit[6] = tiles[index][idx1] & 0b01000000;
		bit[7] = tiles[index][idx1] & 0b10000000;

		int bit2[8];

		bit2[0] = tiles[index][idx1 + 1] & 0b00000001;
		bit2[1] = tiles[index][idx1 + 1] & 0b00000010;
		bit2[2] = tiles[index][idx1 + 1] & 0b00000100;
		bit2[3] = tiles[index][idx1 + 1] & 0b00001000;
		bit2[4] = tiles[index][idx1 + 1] & 0b00010000;
		bit2[5] = tiles[index][idx1 + 1] & 0b00100000;
		bit2[6] = tiles[index][idx1 + 1] & 0b01000000;
		bit2[7] = tiles[index][idx1 + 1] & 0b10000000;

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

		for (size_t i = 0; i < 8; i++)
		{
			utils::SetColor(colors[i]);
			utils::FillRect(leftBottom, 4, 4);
			leftBottom.x += 4;
		}

		leftBottom.x = 0.f;
		leftBottom.y -= 4;

	}
}

void Level::Draw(unsigned char sprites[256][16], unsigned char backGround[256][16],
	OAMEntry oam[40], unsigned char grid[1024], unsigned char x, unsigned char y) const
{
	//Draw background
	Point2f startPos{ 0,32 * 8 };
	unsigned char idx{};
	for (int rows = 0; rows < 32; rows++)
	{
		for (int cols = 0; cols < 32; cols++)
		{
			idx = rows * 32 + cols;
			DrawTile(backGround, idx);
			startPos.x += 32.0f;
		}
		startPos.x = 0;
		startPos.y -= 32;
	}

	//Draw window rect
	utils::SetColor(Color4f{ 1.f, 0.f, 0.f, 1.f });
	utils::DrawRect(float(x), 255.f - y - 144.f, 160.f, 144.f);

	//Draw Sprites
	for (int i{}; i < 40; ++i)
	{
		DrawSprite(oam[i], x, y, sprites);
	}

}
