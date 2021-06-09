/*Q4 header*/
#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include "Util.h"

chessPosList* findKnightPathCoveringAllBoard(pathTree* path_tree);
void finedFullPathRec(treeNodeListCell* currListHead, chessPosList** lstPtr, int* lvls);
