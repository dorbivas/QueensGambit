/*Q2 header Bitch*/
#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include "Util.h"

/*Q2*/
void display(chessPosList* lst);
void removeExcessCells(chessPosList* lst, int boardValues[BOARD_SIZE][BOARD_SIZE]);
void removeSingleCell(chessPosCell* prevCell, chessPosList* list);
bool checkApearence(int bucket[BOARD_SIZE][BOARD_SIZE], chessPos pos);

/*Checking Functions*/
chessPosCell* Initiate(chessPos data);
void printList(chessPosList* lst);