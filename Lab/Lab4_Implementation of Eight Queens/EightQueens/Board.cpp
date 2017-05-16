/*
* Board.cpp
* CS/IS 211
* Lab #4 - Implemenation of Eight Queens
* Group Member(s): Amy Jiang, Aaron Lim, Charlson So
*/
#include <iostream>
#include <vector>
#include "Board.h"
using namespace std;

/** Supplies the Queen class with a pointer to the board. */
Board::Board() {
	Queen::setBoard(this);
}

/** Clears the board and removes pointer from queens. */
Board::~Board() {
	clear();
}

/** Attempts to place queens on board, starting with the designated queen. */
bool Board::placeQueens(Queen* queenPtr) {
	if (queenPtr->getCol() >= BOARD_SIZE) {
		delete queenPtr;
		return true;
	}

	bool isQueenPlaced = false;

	while (!isQueenPlaced && queenPtr->getRow()<BOARD_SIZE) {

		if (queenPtr->isUnderAttack()) {
			queenPtr->nextRow();
		}
		else {
			setQueen(queenPtr);
			Queen* newQueenPtr = new Queen(0, queenPtr->getCol() + 1);
			isQueenPlaced = placeQueens(newQueenPtr);
			if (!isQueenPlaced) {
				delete newQueenPtr;
				removeQueen();
				queenPtr->nextRow();
			}
		}
	}
	return isQueenPlaced;
}

/** Initiates the Eight Queens problem. */
void Board::doEightQueens(Queen q) {
	placeQueens(new Queen(q.getRow(),q.getCol()));
}

/** Clears board. */
void Board::clear() {
	for (int i = getNumQueens(); i > getNumQueens() ;++i) {
		delete (queens[i]);
	}
	queens.clear();
}

/** Removes the last queen from the board, but does not deallocate it. */
void Board::removeQueen() {
	if (queens.size() != 0)
		queens.pop_back();
}

/** Sees whether a queen exists in position (inRow, inCol). */
bool Board::isQueen(int row, int col) const {
	bool isOnBoard = false;
	for (int i = 0; i < (int)queens.size(); i++) {
		if (queens[i]->getRow() == row && queens[i]->getCol() == col) {
			isOnBoard = true;
		}
	}
	return isOnBoard;
}
/** Places a queen on the board. */
void Board::setQueen(Queen* queenPtr) {
	queens.push_back(queenPtr);
}


/** Displays board. */
void Board::display() const {
	cout << "  ";
	for (int rowNum = 0; rowNum < BOARD_SIZE; rowNum++)
		cout << rowNum << " "; //row numbers
	cout << endl;
	for (int row = 0; row < BOARD_SIZE; row++) {
		cout << row << " "; //this is col numbers
		for (int col = 0; col < BOARD_SIZE; col++) {
			if (isQueen(row, col)) {
				cout << "Q "; //used isQueen() method to check if the vector contains any Queens on the chessboard.
			}
			else cout << "+ "; //no Queen located
		} cout << endl;
	}

}

/** @return The number of queens on the board. */
int Board::getNumQueens() const {
	return queens.size();
}

/** @return A pointer to the queen at the designated index. */
const Queen* Board::getQueen(int index) const {
	return queens[index]; //vector contains Queen pointers
}