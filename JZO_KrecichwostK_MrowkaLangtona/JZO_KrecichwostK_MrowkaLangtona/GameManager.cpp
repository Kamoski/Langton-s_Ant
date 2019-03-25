#include "GameManager.h"
#include <fstream>
#include <iostream>

GameManager::GameManager()
	:
	rows(0)
	, cols(0)
	, maxStep(0)
	, actualSteps(0)
	, hc(GetStdHandle(STD_OUTPUT_HANDLE))
	, deltaTime(0)
{	
	std::fstream file;
	file.open("data.ini", std::ios::in);
	file >> maxStep;
	file >> deltaTime;
	file >> rows;
	file >> cols;
	file >> antCords.x;
	file >> antCords.y;
	file.close();

	map = new Cell*[rows];

	for (int i = 0; i < rows; ++i) {
		map[i] = new Cell[cols];
	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			map[i][j].kill();
		}
	}
	temp.X = 0;
	temp.Y = 0;
	antCords.direction = 4;
}


GameManager::~GameManager()
{

	for (int i = 0; i < rows; ++i) {
		delete [] map[i];
	}
	delete[]map;
	cols = 0;
	rows = 0;
}

void GameManager::drawMap()
{
	if (actualSteps == 0) {

		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {

				if (i == antCords.x && j == antCords.y) {
					std::cout << "M";
				}
				else if (map[i][j].checkState()) {
					std::cout << "o";
				}
				else {
					std::cout << " ";
				}

			}
			std::cout << std::endl;
		}
	}
	else
	{
		temp.X = antCords.xbefore;
		temp.Y = antCords.ybefore;
		SetConsoleCursorPosition(hc, temp);

		if (map[antCords.xbefore][antCords.ybefore].checkState()) {
			std::cout << "o";
		}
		else {
			std::cout << " ";
		}
	}
	antCords.xbefore = antCords.x;
	antCords.ybefore = antCords.y;
}

int GameManager::analysis()
{	
	if (map[antCords.x][antCords.y].checkState()) {
		map[antCords.x][antCords.y].kill();
		moveAnt(true);
	}
	else {
		map[antCords.x][antCords.y].revive();
		moveAnt(false);
	}
	return ++actualSteps;
}

int GameManager::getMaxSteps()
{
	return maxStep;
}

void GameManager::moveAnt(bool whatDirection)
{
	if (!whatDirection) {
		//std::cout << "Respie, pokonalem: " << antCords.direction;
		if (antCords.direction == 1) {
			--antCords.y;
			antCords.direction = 2;
		}

		else if (antCords.direction == 2) {
			++antCords.x;
			antCords.direction = 3;
		}
		
		else if (antCords.direction == 3) {
			++antCords.y;
			antCords.direction = 4;
		}

		else if (antCords.direction == 4) {
			--antCords.x;
			antCords.direction = 1;
		}
	}
	else
	{
		//std::cout << "Zabilem, pokonalem: " << antCords.direction;
		if (antCords.direction == 1) {
			++antCords.y;
			antCords.direction = 4;
		}

		else if (antCords.direction == 2) {
			--antCords.x;
			antCords.direction = 1;
		}

		else if (antCords.direction == 3) {
			--antCords.y;
			antCords.direction = 2;
		}

		else if (antCords.direction == 4) {
			++antCords.x;
			antCords.direction = 3;
		}
	}

	if (antCords.x < 0) {
		antCords.x = rows - 1;
	}
	else if (antCords.x == rows) {
		antCords.x = 0;
	}
	else if (antCords.y < 0)
	{
		antCords.y = cols - 1;
	}
	else if (antCords.y == cols) {
		antCords.y = 0;
	}
	
	//std::cout << " a ide do: " << antCords.direction << " Kroki ogó³em: " << actualSteps;
}

HANDLE GameManager::getHandle()
{
	return hc;
}

int GameManager::getCols()
{
	return cols;
}

int GameManager::getRows()
{
	return rows;
}

int GameManager::getDeltaTime()
{
	return deltaTime;
}
