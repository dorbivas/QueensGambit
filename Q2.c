/*Dor And the Mighty Idan Q2 Bitch*/
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
	int boardValues[BOARD_SIZE][BOARD_SIZE];/* = {
						{0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0},  }; holds the cells that already appeared TODO*/
	for (i = 0; i < BOARD_SIZE; i++)
		for (j = 0; j < BOARD_SIZE; j++)
			boardValues[i][j] = 0;

	removeExcessCells(lst, boardValues);
	printBoard(boardValues);
}

void removeExcessCells(chessPosList* lst, int boardValues[BOARD_SIZE][BOARD_SIZE]) {
	int cellsLocation = 1; /*holds the the location appearnce of a cell in the list*/
	chessPosCell* curr, * prev, * tmp;

	curr = prev = lst->head;

	while (curr != NULL) {
		if (checkApearence(boardValues, curr->position))
		{
			/*updates the bucket to its order appearnce (true) and advance the counter*/
			boardValues[charToInt(curr->position[0])][charToInt(curr->position[1])] = cellsLocation++;
			prev = curr;
			curr = curr->next;
		}
		else
		{
			tmp = curr->next;
			removeSingleCell(prev, lst);
			curr = tmp;
		}
	}

}

bool checkApearence(int boardValues[BOARD_SIZE][BOARD_SIZE], chessPos pos) {
	return ((boardValues[charToInt(pos[0])][charToInt(pos[1])]) == 0);
}

void removeSingleCell(chessPosCell* prevCell, chessPosList* list) { /*TODO check if list needed?*/

	chessPosCell* curr = prevCell->next;

	prevCell->next = curr->next;
	if (prevCell->next == NULL)
		list->tail = prevCell;

	free(curr);
}

/*Checking functions*/ /*TODO: check funcs on util?*/
/*Q2*/
chessPosCell* Initiate(chessPos data)
{
	chessPosCell* newCell = (chessPosCell*)malloc(sizeof(chessPosCell));
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
