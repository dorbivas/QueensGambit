/*Q5 header*/
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Util.h"
typedef unsigned char Byte; 

void saveListBinFile(char* file_name, chessPosList* pos_list);
short listSize(chessPosCell* curr);

Byte posToByte(char pos);
void insertBytes(chessPosCell** curr, short amount, FILE* fp);
void init2PosBytes(Byte* b);
void init3PosBytes(Byte* b);
void init4PosBytes(Byte* b);
Byte createChessPosByte(chessPosCell* curr);
