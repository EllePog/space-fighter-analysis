#include "Score.h"
#include "GameplayScreen.h"


int Score::score = 0;

bool Score::TargetAquired() const {
	if (score == targetScore) { return true; }
	else {return false; }
}

int Score::Hit() const {
	m_score = score++;
	return m_score;
}

int Score::UpdateScore() const {
	m_score = score; 
	return score;
}

void Score::NextLevel() const {
	if (madeIt == true) {
		int levelIndex = 1;
		GameplayScreen::GameplayScreen(levelIndex);
	}
}

void Score::ResetScore() const {
	score = 0;
	std::cout << score;
	return;
}