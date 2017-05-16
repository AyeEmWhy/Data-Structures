/*
* test.cpp
* CS/IS 211
* Lab #4 - Implemenation of Eight Queens
* Group Member(s): Amy Jiang, Aaron Lim, Charlson So
*/
#include <iostream>
#include <vector>
#include "Queen.h"
#include "Board.h"
using namespace std;

int main() {
	/**display all possible solutions**/
	Board board;
	for (int row = 0; row < 8; row++) {
		Queen queen(row, 0);
		queen.setBoard(&board);
		board.doEightQueens(queen);
		board.display();
		board.clear();
		cout << endl;
	}
	system("PAUSE");
	return 0;
}