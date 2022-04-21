#include "pch.h"
#include "Character.h"
#include <iostream>

Character::Character() :
	m_Shape{},
	m_Velocity{},
	m_JumpSpeed{ 600 },
	m_State{ State::idle },
	m_Gravity{ -1000 },
	m_HorSpeed{ 300 },
	m_HasPressedJump{},
	m_HasDashed{}
{}

void Character::Update(float elapsedSec)
{
	m_Shape.bottom += m_Velocity.y * elapsedSec;
	m_Shape.left += m_Velocity.x * elapsedSec;
	m_Velocity.y += m_Gravity * elapsedSec;

	HandleKeyInputs();
}

void Character::HandleKeyInputs()
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	if (pStates[SDL_SCANCODE_A])
	{
		m_State = State::move;
		m_Velocity.x = -m_HorSpeed;
	}
	else if (pStates[SDL_SCANCODE_D])
	{
		m_State = State::move;
		m_Velocity.x = m_HorSpeed;
	}
	else
	{
		if (m_State == State::move) m_State = State::idle;
		m_Velocity.x = 0;
	}

	if (pStates[SDL_SCANCODE_K] && !m_HasPressedJump)
	{
		m_State = State::jump;
		m_Velocity.y = m_JumpSpeed;
	}

	if (pStates[SDL_SCANCODE_J] && !m_HasDashed)
	{
		const float dashDistance{ 30 };
		m_State = State::dash;
		if (m_IsFacingRight) m_Shape.left += dashDistance;
		else m_Shape.left -= dashDistance;
		m_HasDashed = true;
	}
}



Rectf& Character::GetShape()
{
	return m_Shape;
}

Vector2f& Character::GetVelocity()
{
	return m_Velocity;
}