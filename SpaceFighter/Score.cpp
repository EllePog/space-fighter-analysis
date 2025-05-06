#include "Score.h"
#include "GameplayScreen.h"
#include "Level.h"


int Score::score = 0;
bool Score::m_Aquired = false;
int Score::targetScore = 15;
bool Score::done = false;
bool Score::timer_started = false;
chrono::steady_clock::time_point Score::start = std::chrono::steady_clock::now();