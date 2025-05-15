
#include "GameplayScreen.h"
#include "MainMenuScreen.h"
#include "Level.h"
#include "Level02.h"
#include "Level01.h"




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
	m_pResourceManager = &resourceManager;;
	//if (m_pLevel && m_pLevel->TargetAquired()) {
	//	m_levelIndex = 1;
	//}
	LoadLevel(m_levelIndex);
	
}


void GameplayScreen::LoadLevel(int levelIndex)
  {	
	//if  (m_pLevel && m_pLevel->TargetAquired()) {
	//	levelIndex = 1;
	//}
	//else
	//{
	//	levelIndex = 0;
	//}
	if (levelIndex == 2) { levelIndex = 0; m_levelIndex = 0; }
	if (m_pLevel) delete m_pLevel;
	switch (levelIndex)
	{
	case 0: m_pLevel = new Level01(); break;
	case 1: m_pLevel = new Level02(); break;
	}
	std::cout << "\nThis is actually level " << levelIndex;
	m_pLevel->SetGameplayScreen(this);
	m_pLevel->LoadContent(*m_pResourceManager);
	m_pLevel->SetLevelIndex(levelIndex);
	//m_pLevel->NextLevel();
	
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
