/* Q1 header bitch*/
#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include "Util.h"

/*Q1*/
chessPosArray*** validKnightMoves();
chessPos* validSquareMoves(int rows, int cols, Coords scanCoords[], unsigned int* size);
chessPosArray*** initiateChessBoard();
bool isInBoard(int rows, int cols);

