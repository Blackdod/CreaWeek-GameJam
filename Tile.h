#pragma once
class Tile
{
public:
	Tile(unsigned char tile[16]);
	~Tile();

	void Draw() const;
private:
	static const int m_NrHex{ 16 };
	static const int m_NrPixels{ 64 };
	unsigned int m_TileLabel[m_NrHex];

	const int m_NrRows;
	const int m_NrColumns;

	const std::string m_TileName;

	const float m_Scale;

	const float m_PixelWidth;
	const float m_PixelHeight;

	static const Color4f m_DarkestGreen;
	static const Color4f m_DarkGreen;
	static const Color4f m_LightGreen;
	static const Color4f m_LightestGreen;

	static const int m_Divide;
};