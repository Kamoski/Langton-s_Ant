#ifndef _GAME_
#define _GAME_

#include "GameManager.h"

class Game : public GameManager
{
public:
	Game() {

	}

	Game(GameManager*& obj) {
		GameInstance = new GameManager();
		obj = GameInstance;
	}

	virtual ~Game() {
		this->GameInstance->~GameManager();
	}

	void startGame() {
		while (GameInstance->getMaxSteps() != GameInstance->analysis())
		{
			view();
		}
		endGame();
	}
	virtual void endGame() = 0;
	virtual void view() = 0;
private:
	GameManager *GameInstance;
};

#endif
