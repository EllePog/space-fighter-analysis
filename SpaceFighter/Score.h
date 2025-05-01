#include <iostream>
#pragma once

class Score
{
private:

	static int score;
	mutable int m_score;
	int hit = 1;
	int targetScore = 15;
	static bool m_Madeit;
	static bool m_Aquired;
	static int m_targetScore;

public:
	mutable bool madeIt = false;

	virtual ~Score() {}

	Score() {};

	virtual int Hit() {	m_score = score++; return m_score; };

	virtual void GetScore() { std::cout << "\n" << score << "\n"; TargetAquired(); }

	virtual int UpdateScore();

	static bool TargetAquired() {
		if (score == m_targetScore) { return m_Aquired = true; }
		else { return m_Aquired = false; }
	}

	static void NextLevel() { m_Aquired = false; }

	static void ResetScore();
};

