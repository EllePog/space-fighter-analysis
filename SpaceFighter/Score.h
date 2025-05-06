#include <iostream>
#pragma once

class Score
{
private:

	static int score;
	mutable int m_score = 0;
	int hit = 1;
	static int targetScore;
	static bool m_Aquired;

public:

	virtual ~Score() {}

	Score() {};

	virtual int Hit() {	m_score = score++; return m_score; };

	virtual void GetScore() { std::cout << "\n" << score << "\n"; TargetAquired(); }

	virtual int UpdateScore() {	m_score = score; return score;
	};

	static bool TargetAquired() {
		if (score == targetScore) { return m_Aquired = true; }
		else { return m_Aquired = false; }
	}

	static void NextLevel() { m_Aquired = false; }

	static void ResetScore() {
		score = 0;
		return;
	};
};

