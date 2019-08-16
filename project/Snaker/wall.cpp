#include "wall.h"

void Wall::initWall() {
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			if (i == 0 || j == 0 || i == ROW - 1 || j == COL - 1)
				gameArray[i][j] = '*';
			else
				gameArray[i][j] = ' ';
		}
	}
}
void Wall::drawWall() {
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			cout << gameArray[i][j] << " ";
		}
		if (i == 5)
			cout << "\t制作人：yhz";
		if (i == 6)
			cout << "\tW 向上";
		if (i == 7)
			cout << "\tS 向下";
		if (i == 8)
			cout << "\tA 向左";
		if (i == 9)
			cout << "\tD 向右";
		cout << endl;
	}
}
void Wall::setWall(int x, int y, char c) {
	gameArray[x][y] = c;
}
char Wall::getWall(int x, int y) {
	return gameArray[x][y];
}

