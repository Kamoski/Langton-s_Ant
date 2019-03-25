#ifndef _CELL_
#define _CELL_

class Cell
{
public:
	Cell() : isAlive(false) {};
	~Cell() {};
	void kill() { isAlive = false; }
	void revive() { isAlive = true; }
	bool checkState() { return isAlive; }
private:
	bool isAlive;
};

#endif
