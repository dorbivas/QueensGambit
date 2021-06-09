#pragma once
#include "Util.h"
#include <math.h>
#include "Q2.h"
#include "Q5.h"

int checkAndDisplayPathFromFile(char* file_name);
chessPosList* createListFromFile(FILE* fp, int* size);
bool checkValidKnightPath(chessPosList* lst);
bool validSingleMove(chessPos a, chessPos b);