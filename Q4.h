/*Q4 header Bitch*/
#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include "Util.h"

chessPosList* findKnightPathCoveringAllBoard(pathTree* path_tree);
void rec(treeNodeListCell* currListHead, chessPosList** lstPtr, int* lvls, int* recCntr);
