/*Q4 header Bitch*/
#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include "Util.h"

chessPosList* findKnightPathCoveringAllBoard(pathTree* path_tree);
void findKnightPathCoveringAllBoardRec(treeNode* root, treeNodeListCell* currListHead, chessPosList** res, int* lvls);
