/*Dor And the Mighty Idan Util Lib Bitch 315557850*/
#define _CRT_SECURE_NO_WARNINGS
#include "Util.h"

/*Q1 util*/
int IntToCharNum(int num) {
	return '1' + num;
}
int IntToCharLetter(int num) {
	return 'A' + num;
}

/*Q2 util*/
void printRoofNumbers()
{
	printf("        ");
	for (int i = 1; i < BOARD_SIZE + 1; i++)
		printf("%3d   ", i);
	printf("\n\n");
}

void printBoard(int boardValues[BOARD_SIZE][BOARD_SIZE]) {

	printRoofNumbers(BOARD_SIZE);

	for (int row = 0; row < BOARD_SIZE; row++) {
		printf("%3c    |", 'A' + row); /* columns numbers*/
		for (int col = 0; col < BOARD_SIZE; col++) {
			if (boardValues[row][col] == 0)
				printf("     |");
			else
				printf("%3d  |", boardValues[row][col]);
		}
		printf("\n");
	}
	printf("\n");
}

bool comparePos(chessPos a, int row, int col) {
	return ((charToInt(a[0]) == row) && (charToInt(a[1]) == col));
}

int charToInt(char ch) { /*TODO CHANGE NAME*/
	if (ch >= 'A' && ch <= 'Z')
		return (ch - 'A');

	return ch - '1';
}

void checkAlloc(void* ptr, char* msg)
{
	if (!ptr)
	{
		printf("Allocation failed: %s", msg);
		exit(1);
	}
}

/*TODO*/
void chessPosSetter(chessPos* dest, chessPos src) {
	(*dest)[0] = src[0];
	(*dest)[1] = src[1];
}