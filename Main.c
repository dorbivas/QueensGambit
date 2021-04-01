/*Dor bivas Chess Bitch 315557850*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ROWS 8
#define COLS 8

typedef char chessPos[2];

typedef struct _chessPosArray {
	unsigned int size;
	chessPos* positions;
} chessPosArray;

typedef struct _chessPosCell {

	chessPos position;
	struct _chessPosCell* next;

} chessPosCell;

typedef struct _chessPosList {
	chessPosCell* head;
	chessPosCell* tail;
} chessPosList;

void display(chessPosList* first);
void printBoard(chessPosList* first);
void printRoofNumbers();

int charToInt(char ch);

void removeExcessCells(chessPosList* first);
void removeSingleCell(chessPosCell* prevCell, chessPosList* list);

void main()
{

}

void display(chessPosList* first) {
	removeExcessCells(first);
	printBoard(first);
}

void removeExcessCells(chessPosList* first) {
	bool bucket[ROWS][COLS] = {
							{0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0}, };
	chessPosCell* curr, * prev;

	curr = first->head;

	while (curr != NULL) {
		if (checkApearence(bucket, curr->position))
		{
			removeSingleCell(prev, first);
			bucket[charToInt(curr->position[0]) - 1][charToInt(curr->position[1]) - 1] = 1;/*updates the bucket 1 (true)*/
		}
		/*advance the pointer*/
		prev = curr;
		curr = curr->next;
	}

}

bool checkApearence(bool bucket[ROWS][COLS], chessPos pos) {
	return (bucket[charToInt(pos[0]) - 1][charToInt(pos[1]) - 1]);
}

void removeSingleCell(chessPosCell* prevCell, chessPosList* list) { /*TODO check if list needed?*/

	chessPosCell* tmp = prevCell->next;

	/*remove last cell*/
	if (tmp->next == NULL)
	{
		free(tmp);
		prevCell->next = NULL;
		list->tail = prevCell;
	}
	else {
		prevCell->next = tmp->next;
		free(tmp);
	}
}

void printRoofNumbers()
{
	printf("        ");
	for (int i = 0; i < COLS; i++)
		printf("%3d   ", i);
	printf("\n\n");
}

void printBoard(chessPosList* first) {

	chessPosCell* curr;
	int counter = 1;

	curr = first->head;
	printRoofNumbers(COLS);

	for (int row = 0; row < ROWS; row++) {
		printf("%3c    |", 'A' + row); /* columns numbers*/
		for (int col = 0; col < COLS; col++) {
			if (comparePos(curr->position, row, col) && curr != NULL)
			{
				printf("%3d  |", counter++);
				curr = curr->next;
			}
		}
		printf("\n");
	}
	printf("\n");
}

bool comparePos(chessPos a, int row, int col) {
	return ((charToInt(a[0]) == (row + 1)) && (charToInt(a[1]) == (col + 1)));
}

int charToInt(char ch) {
	if (ch >= 'A' && ch <= 'Z')
		return (ch - 'A') + 1;

	return '0' + ch;
}


