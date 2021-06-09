/*Q3 header*/
#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include "Util.h"

typedef struct _treeNode treeNode;
typedef struct _treeNodeListCell treeNodeListCell;

typedef struct _treeNode {
	chessPos position;
	treeNodeListCell* next_possible_positions;
} treeNode;

typedef struct _treeNodeListCell {
	treeNode* node;
	struct _treeNodeListCell* next;
} treeNodeListCell;

typedef struct _pathTree {
	treeNode* roots;
}pathTree;

pathTree findAllPossibleKnightPaths(chessPos* startingPosition);
void pathBuildRec(treeNode* root, chessPosArray*** validMovesBoard, bool ** visitsMatrix);
void printPath(pathTree path);
void printPathRec(treeNode* root);

chessPosArray nextKnightPositions(chessPosArray*** validMovesBoard, chessPos currPos);
void updateVisitMatrix(bool ** visitsMatrix, chessPos pos);

void insertDataToHeadList(treeNodeListCell ** oldHead, chessPos pos);
void insertNodeToHeadList(treeNodeListCell* newHead, treeNodeListCell ** oldHead);

bool** CreateVisitsMatrix(int size);
bool isVisited(bool** visitsMatrix, chessPos pos);
pathTree CreatePathTree(chessPos pos);
treeNodeListCell* CreateListCell(chessPos pos);
treeNodeListCell* CreateNextPosList(bool** visitsMatrix, chessPosArray allNextPositions);

void freePath(pathTree* path);
void freePathRec(treeNodeListCell* cell);
void freeVisitsMatrix(bool** matrix);

/*TEST funcs*/
void testNextKNightPos();
