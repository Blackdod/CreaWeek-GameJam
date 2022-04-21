#pragma once
#include "Vector2f.h"

class Character
{
public:
	Character();

	void Update(float elapsedSec);
	Rectf& GetShape();
	Vector2f& GetVelocity();

private:
	Rectf m_Shape;
	Vector2f m_Velocity;
	const float m_JumpSpeed;
	enum class State { idle, move, jump, dash };;
	State m_State;
	const float m_Gravity;
	const float m_HorSpeed;
	bool m_HasPressedJump;
	bool m_HasDashed;
	bool m_IsFacingRight;

	void HandleKeyInputs();
};

