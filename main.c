#include "Util.h"
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"
#include "Q4.h"
#include "Q5.h"
#include "Q7.h" /*TODO CHANGE*/

void testQ4();
chessPosList* createListTest();

void test5();

void main() {

	menu();
	test5();
	//testQ4();
	//test();
}

chessPosList* createListTest() {
	chessPosList* testList = (chessPosList*)malloc(sizeof(chessPosList));
	makeEmptyList(testList);
	chessPosCell *a1, * a2, * a3, * a4, * a5;
	a1 = Initiate((chessPos) { 'E', '3' });
	a2 = Initiate((chessPos) { 'C', '4' });
	a3 = Initiate((chessPos) { 'A', '3' });
	a4 = Initiate((chessPos) { 'B', '1' });
	a5 = Initiate((chessPos) { 'D', '2' });

	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = a5;

	testList->head = a1;
	testList->tail = a5;
	return testList;
}

void test5() {
	
	//chessPos pos = { 'E','3' };
	//pathTree path;
	//chessPosList* fullPath;
	//path = findAllPossibleKnightPaths(&pos);
	//fullPath = findKnightPathCoveringAllBoard(&path);
	chessPosList* testList = createListTest();

	saveListBinFile("testQ5.bin", testList);

	//freePath(&path);
	//if (fullPath) {
	//	display(fullPath);
	//	freeListCell(fullPath);
	//}
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