#ifndef _GAMEMANAGER_
#define _GAMEMANAGER_
#include <Windows.h>
#include "Cell.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

	void drawMap();
	int analysis();

	int getMaxSteps();
	void moveAnt(bool whatDirection);
	
	HANDLE getHandle();

	int getCols();
	int getRows();
	int getDeltaTime();

private:
	Cell **map;
	int rows, cols;
	struct cords {
		int x;
		int y;
		int xbefore;
		int ybefore;
		int direction;
	};
	cords antCords;

	int maxStep;
	int actualSteps;
	HANDLE hc;
	COORD temp;

	int deltaTime;

};

#endif // !_GAMEMANAGER_