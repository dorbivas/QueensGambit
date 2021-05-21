#include "Util.h"
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"
#include "Q4.h"

void testQ4();
void test();

void main() {
	//testQ4();
	test();
}

void test() {
	
	chessPos pos = { 'E','3' };
	pathTree path;
	chessPosList* fullPath;
			path = findAllPossibleKnightPaths(&pos);
			fullPath = findKnightPathCoveringAllBoard(&path);

			freePath(&path);
			if (fullPath) {
				display(fullPath);
				freeListCell(fullPath);
			}
}

void testQ4() {
	int row, col;
	int testBoard[MAX_MOVES][MAX_MOVES];
	chessPos pos;
	pathTree path;
	chessPosList* fullPath;
	for (row = 0; row < MAX_MOVES; row++) {
		for (col = 0; col < MAX_MOVES; col++) {
			pos[0] = IntToCharLetter(row); 
			pos[1] = IntToCharNum(col);
		
			path = findAllPossibleKnightPaths(&pos);
			fullPath = findKnightPathCoveringAllBoard(&path);
			
			if (fullPath)
				testBoard[row][col] = 1;
			else
				testBoard[row][col] = 0;
			freePath(&path);
			if(fullPath)
				freeListCell(fullPath);
			
		}
	}
	printBoard(testBoard);
}