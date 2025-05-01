#include <iostream>
#pragma once

class Score
{
private:

	static int score;
	mutable int m_score;
	int hit = 1;
	int targetScore = 15;
	

public:
	mutable bool madeIt = false;

	virtual ~Score() {}

	Score() {};

	virtual int Hit() const;

	virtual void GetScore() const { std::cout << "\n" << score << "\n"; }

	virtual int UpdateScore() const;

	virtual bool TargetAquired() const;

	void MadeIt() const { if (TargetAquired() == true) { std::cout << "\nMade it."; madeIt = true; } }

	virtual void NextLevel() const;

	virtual void ResetScore() const;
};

