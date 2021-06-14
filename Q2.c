/*QueensGambit Q2 */
#define _CRT_SECURE_NO_WARNINGS
#include "Q2.h"

/*void mainQ2()
{
	chessPosList lst;
	chessPosCell* a1, * a2, * a3, * a4, * a5;
	a1 = Initiate((chessPos) { 'B', '5' });
	a2 = Initiate((chessPos) { 'A', '3' });
	a3 = Initiate((chessPos) { 'F', '6' });
	a4 = Initiate((chessPos) { 'A', '3' });
	a5 = Initiate((chessPos) { 'A', '5' });

	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = a5;

	lst.head = a1;
	lst.tail = a5;

	printf("\nbefore: \n\n ");
	printList(&lst);

	printf("\display : \n \n");
	display(&lst);

}*/

/*Q2*/
void display(chessPosList* lst) {
	int i, j;
	int** boardValues = createBoard();

	removeExcessCells(lst, boardValues);
	printBoard(boardValues);
	freeBoard(boardValues);
	return;
}

void removeExcessCells(chessPosList* lst, int** boardValues) {
	int cellsLocation = 1; /*holds the the location appearnce of a cell in the list*/
	chessPosCell* curr, * prev, * tmp;

	curr = prev = lst->head;

	while (curr != NULL) {
		if (checkApearence(boardValues, curr->position)) {
			/*updates the bucket to its order appearnce (true) and advance the counter*/
			boardValues[charToChessValue(curr->position[0])][charToChessValue(curr->position[1])] = cellsLocation++;
			prev = curr;
			curr = curr->next;
		}
		else {
			tmp = curr->next;
			removeSingleCell(prev, lst);
			curr = tmp;
		}
	}
}

bool checkApearence(int** boardValues, chessPos pos) {
	return ((boardValues[charToChessValue(pos[0])][charToChessValue(pos[1])]) == 0);
}

void removeSingleCell(chessPosCell* prevCell, chessPosList* list) {
	chessPosCell* curr = prevCell->next;

	prevCell->next = curr->next;
	if (prevCell->next == NULL)
		list->tail = prevCell;

	free(curr);
}


chessPosCell* Initiate(chessPos data)
{
	chessPosCell* newCell = (chessPosCell*)malloc(sizeof(chessPosCell));
	checkAlloc(newCell, "failed to alloc newCell");
	newCell->position[0] = data[0];
	newCell->position[1] = data[1];
	newCell->next = NULL;
	return newCell;
}

void printList(chessPosList* lst)
{
	chessPosCell* curr;
	curr = lst->head;
	while (curr != NULL)
	{
		if (curr->next == NULL)
			printf("(%c , %c)--->NULL", curr->position[0], curr->position[1]);
		else
			printf("(%c , %c)--->", curr->position[0], curr->position[1]);

		curr = curr->next;
	}
	printf("\n");
}

int** createBoard() {
	int i;
	int** boardValues = (int**)calloc(BOARD_SIZE, sizeof(int*));
	checkAlloc(boardValues, "failed to allocate values board");
	for (i = 0; i < BOARD_SIZE; i++) {
		boardValues[i] = (int*)calloc(BOARD_SIZE, sizeof(int));
		checkAlloc(boardValues[i], "failed to allocate values board row");
	}
	return boardValues;
}

void freeBoard(int** boardValues) {
	int i;
	for (i = 0; i < BOARD_SIZE; i++)
		free(boardValues[i]);
	free(boardValues);
}