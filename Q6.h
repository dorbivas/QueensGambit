#pragma once
#include "Util.h"
#include "Q2.h"
#include "Q5.h"


int checkAndDisplayPathFromFile(char* file_name);

chessPosList* createListFromFile(FILE* fp, int* size);
