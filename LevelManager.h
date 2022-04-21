#pragma once
#include <vector>

class Level;

class LevelManager final
{
public:
	enum class LevelState
	{
		END,
		TRANSITION,
		RUNNING
	};
	LevelManager();
	LevelManager(const LevelManager& c) = delete;
	LevelManager& operator=(const LevelManager& rhs) = delete;
	LevelManager(LevelManager&& c) = delete;
	LevelManager& operator=(LevelManager&& rhs) = delete;

	void AddLevel(Level* level);
	void Update(float elapsedSec);
	void Draw() const;
private:
	std::vector<Level*> m_pLevels;
	//bool m_IsLevelDone;
	int m_CurrentLevel;

	float m_TransitionTime;
	const float m_MaxTransitionTime;

	LevelState m_LevelState;
	
};

