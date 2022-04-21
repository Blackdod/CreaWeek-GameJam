#pragma once
#include "Vector2f.h"

class Slime
{
public:
	Slime(Point2f spawnPos);
	void Draw() const;
	void Update(float elapsedSec);
	Rectf GetShape() const;

private:
	Rectf m_Shape;
	Vector2f m_Velocity;
};

