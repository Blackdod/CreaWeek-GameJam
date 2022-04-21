#pragma once
class Camera final
{
public:
	Camera(float width, float height);
	void SetLevelBoundaries(const Rectf& levelBoundaries);
	void Transform(const Rectf& target);

	Rectf GetCameraRect() const;

private:
	const float m_Width;
	const float m_Height;
	Rectf m_LevelBoundaries;

	Rectf m_CameraRect;

	Point2f Track(const Rectf& target);
	void Clamp(Point2f& bottomLeftPos);
};

