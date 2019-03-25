#include "GameC.h"
#include <Windows.h>

GameC::GameC()
	:
	Game(GameInstance)
{
}

GameC::~GameC()
{
	
}

void GameC::endGame()
{
	Sleep(300);
	COORD temp;
	temp.X = 0;
	temp.Y = GameInstance->getRows();
	SetConsoleCursorPosition(GameInstance->getHandle(), temp);
	system("exit");
}

void GameC::view()
{
	GameInstance->drawMap();
	Sleep(GameInstance->getDeltaTime());
}
