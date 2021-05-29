/*Q5 header Bitch*/
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Util.h"
typedef unsigned char Byte;

Byte posToByte(char pos);
void saveListBinFile(char* file_name, chessPosList* pos_list);

short listSize(chessPosCell* curr);

void insertBytes(chessPosCell** curr, short amount, FILE* fp);

void init2PosBytes(Byte* b);

void init3PosBytes(Byte* b);

void init4PosBytes(Byte* b);

Byte createChessPosByte(chessPosCell* curr);
