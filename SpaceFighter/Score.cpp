#include "Score.h"
#include "GameplayScreen.h"
#include "Level.h"


int Score::score = 0;

int Score::UpdateScore() {
	m_targetScore = targetScore;
	m_score = score; 
	return score;
}

void Score::ResetScore() {
	score = 0;
	return;
}