#include "pch.h"
#include "LevelManager.h"
#include "level.h"

LevelManager::LevelManager()
	:m_pLevels{}
	, m_CurrentLevel{}
	, m_MaxTransitionTime{1.f}
	, m_TransitionTime{0.f}
	, m_LevelState{LevelState::TRANSITION}
{

}

void LevelManager::AddLevel(Level* level)
{
	m_pLevels.push_back(level);
}

void LevelManager::Update(float elapsedSec)
{
	switch (m_LevelState)
	{
	case LevelState::TRANSITION:
		m_TransitionTime += elapsedSec;
		if (m_TransitionTime >= m_MaxTransitionTime)
		{
			++m_CurrentLevel;
			if (m_CurrentLevel < m_pLevels.size())
			{
				m_LevelState = LevelState::RUNNING;
			}
			else
			{
				m_LevelState = LevelState::END;
			}
			m_TransitionTime = 0.f;
		}
		break;
	case LevelState::RUNNING:
		m_pLevels[m_CurrentLevel]->Update(elapsedSec);
		if (m_pLevels[m_CurrentLevel]->HasReachedEnd())
		{
			m_LevelState = LevelState::TRANSITION;
		}
		break;
	case LevelState::END:
		m_LevelState = LevelState::TRANSITION;
		break;
	}	
}

void LevelManager::Draw() const
{

	switch (m_LevelState)
	{
	case LevelState::TRANSITION:
		
		break;
	case LevelState::RUNNING:
		break;
	case LevelState::END:
		
		break;
	}
	//m_pLevels[m_CurrentLevel]->Draw();
}