/*Q3 header Bitch*/
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

void testNextKNightPos();

void printPath(pathTree path);

void printPathRec(treeNode* root);

pathTree findAllPossibleKnightPaths(chessPos* startingPosition);

void pathBuildRec(treeNode* root, chessPosArray*** validMovesBoard, bool ** visitsMatrix);

treeNodeListCell* CreateNextPosList(bool ** visitsMatrix, chessPosArray allNextPositions);

bool* peeler(bool*** visitsMatrix, chessPos pos);

bool isVisited(bool ** visitsMatrix, chessPos pos);

chessPosArray nextKnightPositions(chessPosArray*** validMovesBoard, chessPos* currPos);

void updateVisitMatrix(bool ** visitsMatrix, chessPos pos);

bool** CreateVisitsMatrix(int size);

void insertDataToHeadList(treeNodeListCell ** oldHead, chessPos pos);

void insertNodeToHeadList(treeNodeListCell* newHead, treeNodeListCell ** oldHead);

pathTree CreatePathTree(chessPos pos);

void CreateListCell(treeNodeListCell* head, chessPos pos);

treeNodeListCell* CreateListCellnotvoid(chessPos pos);

void freePath(pathTree* path);

void freePathRec(treeNodeListCell* cell, int* cntr);


