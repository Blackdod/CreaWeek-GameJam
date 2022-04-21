#include "pch.h"
#include "Camera.h"
#include "utils.h"

Camera::Camera(float width, float height)
	:m_Width{ width }
	,m_Height{ height }
	,m_LevelBoundaries{0,0,width,height}
	,m_CameraRect{}
{
}

void Camera::SetLevelBoundaries(const Rectf& levelBoundaries)
{
	m_LevelBoundaries = levelBoundaries;
}

void Camera::Transform(const Rectf& target)
{
	Point2f bottomLeft{ Track(target) };
	Clamp(bottomLeft);
	Rectf cameraRect{ bottomLeft.x, bottomLeft.y, m_Width, m_Height };

	m_CameraRect = cameraRect;
	
	glTranslatef(-cameraRect.left, -cameraRect.bottom, 0);

}

Point2f Camera::Track(const Rectf& target)
{
	float xValue{ (target.left + target.width / 2) - m_Width / 2 };
	float yValue{ (target.bottom + target.height / 2) - m_Height / 2 };
	return Point2f{ xValue, yValue };
}

void Camera::Clamp(Point2f& bottomLeftPos)
{
	if (bottomLeftPos.x < m_LevelBoundaries.left)
	{
		bottomLeftPos.x = m_LevelBoundaries.left;
	}
	if (bottomLeftPos.y < m_LevelBoundaries.bottom)
	{
		bottomLeftPos.y = m_LevelBoundaries.bottom;
	}
	if (bottomLeftPos.x + m_Width > m_LevelBoundaries.width)
	{
		bottomLeftPos.x = m_LevelBoundaries.width - m_Width;
	}
	if (bottomLeftPos.y + m_Height > m_LevelBoundaries.height)
	{
		bottomLeftPos.y = m_LevelBoundaries.height - m_Height;
	}
}

Rectf Camera::GetCameraRect() const
{
	return m_CameraRect;
}