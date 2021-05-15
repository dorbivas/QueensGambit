/*Dor And the Mighty Idan Util Lib Bitch */
#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BOARD_SIZE 4
#define MAX_MOVES 8

typedef char chessPos[2];

typedef struct _chessPosArray {
	unsigned int size;
	chessPos* positions;
} chessPosArray;

/*Q2 Structs*/
typedef struct _chessPosCell {

	chessPos position;
	struct _chessPosCell* next;

} chessPosCell;

typedef struct _chessPosList {
	chessPosCell* head;
	chessPosCell* tail;
} chessPosList;

typedef int Coords[2];

void checkAlloc(void* ptr, char* msg);

void chessPosSetter(chessPos* dest, chessPos src);

/*Q1*/
int IntToCharNum(int num);
int IntToCharLetter(int num);

/*Q2*/
void printBoard(int boardValues[BOARD_SIZE][BOARD_SIZE]);
void printRoofNumbers();
bool comparePos(chessPos a, int row, int col);
int charToInt(char ch);


