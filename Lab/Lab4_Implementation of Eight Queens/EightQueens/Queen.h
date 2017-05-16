/*
* Queens.h
* CS/IS 211
* Lab #4 - Implemenation of Eight Queens
* Group Member(s): Amy Jiang, Aaron Lim, Charlson So
*/
#ifndef QUEEN_H
#define QUEEN_H

class Board; // Forward declaration of Board class
//definition: Forward declaration of an identifier (denoting an entity such as a type, a variable, or a function)
//for which the programmer has not yet given a complete definition.

/** The Queen class. */
class Queen {
	public:
		Queen(); /** Places a queen in upper-left corner of board. */
		~Queen(); /** Destructor for Queen */
		Queen(int inRow, int inCol); /** Places a queen in supplied location. */ 
		int getCol() const; /** @return Column number. */
		int getRow() const; /** @return Row number. */
		void nextRow(); /** Moves queen to next row. */
		static void setBoard(Board* bPtr); /** Saves a pointer to the board for all queens. */
		bool isUnderAttack() const; /** Sees whether the queen is under attack by another queen.
									@return True if another queen is in the same row or the same
									diagonal; otherwise, returns false. */
	private:
		int row; // Row (or prospective row) of queen if it is on the board
		int col; // Column (or prospective column) of queen if it is on the board
		static const Board* boardPtr; // All queens share the same board



}; //end Queen
#endif