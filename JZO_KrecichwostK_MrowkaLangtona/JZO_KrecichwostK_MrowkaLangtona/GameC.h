#ifndef _GAMEC_
#define _GAMEC_
#include "Game.h"

class GameC : public Game
{
public:
	GameC();
	virtual ~GameC();

	virtual void endGame();
	virtual void view();
private:
	GameManager *GameInstance;
};

#endif
