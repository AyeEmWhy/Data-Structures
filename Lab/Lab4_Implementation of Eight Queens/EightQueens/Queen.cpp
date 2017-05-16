/*
* Queens.cpp
* CS/IS 211
* Lab #4 - Implemenation of Eight Queens
* Group Member(s): Amy Jiang, Aaron Lim, Charlson So
*/
#include "Queen.h"
#include "Board.h"
#include <iostream>
using namespace std;

const Board* Queen::boardPtr;

Queen::Queen() : row(0), col(0) {
	//default initalizer to start queen at top left
}

Queen::Queen(int inRow, int inCol) : row(inRow), col(inCol) {
	//specified starting row & column.

}

Queen::~Queen() {

}

/**@return Col number.**/
int Queen::getCol() const {
	return col;
}

/**@return Row number.**/
int Queen::getRow() const {
	return row;
}
/**Moves queen to next row.**/
void Queen::nextRow() {
	++row;	  
}

/** Sees whether the queen is under attack by another queen.
@return True if another queen is in the same row or the same
diagonal; otherwise, returns false. */
bool Queen::isUnderAttack() const {
	for (int i = 0; i < boardPtr->getNumQueens(); i++) {
		const Queen* q = boardPtr->getQueen(i);
		if (q->getCol() == col || q->getRow() == row || q->getRow()-q->getCol() == row-col || q->getRow()+q->getCol() == row+col)
			return true;
	}
	return false;
}

/** Saves a pointer to the board for all queens. */
void Queen::setBoard(Board* bPtr) {
	 boardPtr = bPtr; //Note: const Board* Queen::boardPtr = bPtr is used if not part of queen class
}


