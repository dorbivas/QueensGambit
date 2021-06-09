/*Q2 header Bitch*/
#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include "Util.h"

/*Q2*/
void display(chessPosList* lst);
void removeExcessCells(chessPosList* lst, int** boardValues);
void removeSingleCell(chessPosCell* prevCell, chessPosList* list);
bool checkApearence(int** boardValues, chessPos pos);

/*Checking Functions*/
chessPosCell* Initiate(chessPos data);
void printList(chessPosList* lst);

int** createBoard();

void freeBoard(int** boardValues);