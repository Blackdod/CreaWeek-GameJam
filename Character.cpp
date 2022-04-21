#include "pch.h"
#include "Character.h"
#include "utils.h"
#include <iostream>

Character::Character(const Point2f& pos) :
	m_Shape{ pos.x, pos.y, 50, 70 },
	m_Velocity{},
	m_JumpSpeed{ 600 },
	m_State{ State::idle },
	m_Gravity{ -1200 },
	m_HorSpeed{ 300 },
	m_HasPressedJump{},
	m_IsFacingRight{ true },
	m_DashTimer{}
{}


void Character::Draw() const
{
	utils::SetColor(Color4f(1, 0, 0, 1));
	utils::FillRect(m_Shape);
}

void Character::Update(float elapsedSec)
{
	m_Shape.bottom += m_Velocity.y * elapsedSec;
	m_Shape.left += m_Velocity.x * elapsedSec;

	if (m_State != State::dash)
		HandleKeyInputs();

	//testing collsion
	if (m_Shape.bottom <= 0)
	{
		m_Shape.bottom = 0;
	}
	else
		m_Velocity.y += m_Gravity * elapsedSec;

	if (m_Velocity.x > 0) m_IsFacingRight = true;
	else if (m_Velocity.x < 0) m_IsFacingRight = false;

	Dash(elapsedSec);
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
		m_HasPressedJump = true;
	}
	if (!pStates[SDL_SCANCODE_K] && m_Shape.bottom <= 2)
	{
		m_HasPressedJump = false;
	}

	if (pStates[SDL_SCANCODE_J] && m_DashTimer == 0)
	{
		m_State = State::dash;
	}
	if (!pStates[SDL_SCANCODE_J] && m_Shape.bottom <= 2)
		m_DashTimer = 0;
}


void Character::Dash(float elapsedSec)
{
	if (m_State == State::dash)
	{
		const float dashSpeed{ 1000 };
		m_DashTimer += elapsedSec;
		if (m_DashTimer >= 0.14f)
		{
			m_State = State::idle;
		}
		else
		{
			if (m_IsFacingRight) m_Velocity.x = dashSpeed;
			else m_Velocity.x = -dashSpeed;
		}
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