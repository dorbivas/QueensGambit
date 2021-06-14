/*QueensGambit Q1 */
#define _CRT_SECURE_NO_WARNINGS
#include "Q1.h"

/*Q1*/
chessPosArray*** validKnightMoves() {
	int rows, cols;
	/*Table for knight possiable positions from coord : (0,0) , 8 options around */
	Coords CoordTable[8] = { {-2 , -1}, {-2 , 1},
							 {2 , 1} , {2 , -1},
							 {1 , -2}, {1 , 2} ,
							 {-1 , 2},{-1 , -2} };

	chessPosArray*** board = initiateChessBoard();

	for (rows = 0; rows < BOARD_SIZE; rows++) {
		for (cols = 0; cols < BOARD_SIZE; cols++) {
			board[rows][cols]->positions = validSquareMoves(rows, cols, CoordTable, &(board[rows][cols]->size));
		}
	}
	return board;
}

chessPos* validSquareMoves(int rows, int cols, Coords scanCoords[], unsigned int* size) {

	int i, counter = 0;
	int tempRows, tempCols;
	chessPos* chessPosRes = (chessPos*)malloc(MAX_MOVES * sizeof(chessPos));
	checkAlloc(chessPosRes, "failed to malloc chessPosRes");

	for (i = 0; i < MAX_MOVES; i++) {
		tempRows = rows + scanCoords[i][0];
		tempCols = cols + scanCoords[i][1];

		if (isInBoard(tempRows, tempCols)) {
			chessPosRes[counter][0] = IntToCharLetter(tempRows);
			chessPosRes[counter][1] = IntToCharNum(tempCols);
			counter++;
		}
	}

	chessPosRes = (chessPos*)realloc(chessPosRes, counter * sizeof(chessPos));
	checkAlloc(chessPosRes, "cant realloc chessPosRes");

	*size = counter;
	return chessPosRes;
}

chessPosArray*** initiateChessBoard() {
	int i, j;
	chessPosArray*** board;
	board = (chessPosArray***)malloc(BOARD_SIZE * sizeof(chessPosArray**));
	checkAlloc(board, "failed to alloc board");
	for (i = 0; i < BOARD_SIZE; i++) {

		board[i] = (chessPosArray**)malloc(BOARD_SIZE * sizeof(chessPosArray*));
		checkAlloc(board[i], "failed to alloc board[i]");

		for (j = 0; j < BOARD_SIZE; j++) {
			board[i][j] = (chessPosArray*)malloc(sizeof(chessPosArray));
			checkAlloc(board[i][j], "failed to alloc board[i][j]");
		}
	}
	return board;
}

bool isInBoard(int rows, int cols) {
	return ((rows >= 0 && rows <= (BOARD_SIZE - 1)) && (cols >= 0 && cols <= (BOARD_SIZE - 1)));
}

