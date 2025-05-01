
#include "GameplayScreen.h"
#include "MainMenuScreen.h"
#include "Level.h"
#include "Level02.h"
#include "Level01.h"
#include "Score.h"
#include "Score.cpp"

GameplayScreen::GameplayScreen(const int levelIndex)
	: m_levelIndex(levelIndex)
{
	SetTransitionInTime(1);
	SetTransitionOutTime(3);

	SetOnRemove([this](){ AddScreen(new MainMenuScreen()); });

	Show();
}

void GameplayScreen::LoadContent(ResourceManager& resourceManager)
{
	m_pResourceManager = &resourceManager;
	Score* hit = new Score();
	if (hit->madeIt == true) {
		m_levelIndex = 1;
	}
	LoadLevel(m_levelIndex);
	
}

void GameplayScreen::LoadLevel(int levelIndex)
{
	if (m_pLevel) delete m_pLevel;
	if (Score::TargetAquired() == true) {
		levelIndex = 1; std::cout << "\nThis should be level 1.";
	}
	else
	{
		levelIndex = 0;
		std::cout << "\nThis should be level 0.";
	}

	switch (levelIndex)
	{
	case 0: m_pLevel = new Level01(); break;
	case 1: m_pLevel = new Level02(); break;
	}
	std::cout << "\nThis is actually level " << levelIndex;
	m_pLevel->SetGameplayScreen(this);
	m_pLevel->LoadContent(*m_pResourceManager);
	Score::NextLevel();
	Score::ResetScore();
	std::cout << "\nThis should be level 1 not 0";
}

void GameplayScreen::HandleInput(const InputState& input)
{
	m_pLevel->HandleInput(input);
}

void GameplayScreen::Update(const GameTime& gameTime)
{
	m_pLevel->Update(gameTime);
}

void GameplayScreen::Draw(SpriteBatch& spriteBatch)
{
	spriteBatch.Begin();

	m_pLevel->Draw(spriteBatch);

	spriteBatch.End();
}
