#include <iostream>
#include <chrono>
#include<thread>
#pragma once

using namespace std;
using namespace chrono_literals;

class Score
{
private:

	static int score;
	mutable int m_score = 0;
	int hit = 1;
	static int targetScore;
	static bool m_Aquired;
	static bool done;
	static bool timer_started;

public:

	static chrono::steady_clock::time_point start;

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

	static void StartTimer() {
		start = std::chrono::steady_clock::now();
		timer_started = true;
		cout << "Timer Started.\n";
	}

	static bool DoneStatus() { return done; }

	static bool ResetTimer() { done = false; return done; }

	static bool AllDoneNow() { done = true;  return done; }

	static void TimeForNextLevel() {
		if (timer_started == true) {
			auto timer_duration = 0.55min;
			const auto now = chrono::steady_clock::now();
			if (now - start >= timer_duration) {
				AllDoneNow();
				timer_started = false;
				cout << "Done\n";
			}
		}
	}


	static void NextLevel() { m_Aquired = false; }

	static void ResetScore() {
		score = 0;
		return;
	};
};

