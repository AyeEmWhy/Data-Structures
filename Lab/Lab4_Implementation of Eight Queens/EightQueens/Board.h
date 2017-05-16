/*
* Board.h
* CS/IS 211
* Lab #4 - Implemenation of Eight Queens
* Group Member(s): Amy Jiang, Aaron Lim, Charlson So
*/
#ifndef _BOARD
#define _BOARD
#include "Queen.h"
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

static const int BOARD_SIZE = 8;
class Board {
private:
	vector<Queen*> queens; // Array of pointers to queens on the board	
	bool isQueen(int inRow, int inCol) const ; /** Sees whether a queen exists in position (inRow, inCol). */
	bool placeQueens(Queen* queenPtr);
	void removeQueen();
	void setQueen( Queen* queenPtr); //originally void setQueen(const Queen* queenPtr)

public:
	Board();
	~Board();
	void clear();
	void display() const;
	void doEightQueens(Queen q);
	int getNumQueens() const;
	const Queen* getQueen(int index) const;
};
#endif