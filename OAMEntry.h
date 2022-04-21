#pragma once
class OAMEntry final
{
public:
	OAMEntry(int posX, int posY, int tileID, bool flipX = false, bool flipY = false);
	void SetPosition(int posX, int posY);
	void AddPosition(int posX, int posY);
	Point2f GetPosition() const;

	void FlipX(bool flip);
	void FlipY(bool flip);

	bool GetFlipX();
	bool GetFlipY();

	int GetTileId();
private:
	int m_PosX;
	int m_PosY;
	int m_TileId;
	bool m_FlipX;
	bool m_FlipY;
};

