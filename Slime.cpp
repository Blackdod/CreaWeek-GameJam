#include "pch.h"
#include "Slime.h"
#include "utils.h"

Slime::Slime(Point2f spawnPos)
	:m_Shape{ spawnPos.x, spawnPos.y, 50, 50 }
	,m_Velocity{}
{
}

void Slime::Draw() const
{
	utils::SetColor( Color4f{0.2f,1,0.2f,1} );
	utils::FillRect( m_Shape );
}

void Slime::Update(float elapsedSec)
{
	
}

Rectf Slime::GetShape() const
{
	return m_Shape;
}