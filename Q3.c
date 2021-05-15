/*Dor And the Mighty Idan Q3 Bitch*/
#define _CRT_SECURE_NO_WARNINGS
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"

void main()
{
	//testNextKNightPos();
	chessPos start = { 'A','1' };
	pathTree path = findAllPossibleKnightPaths(&start);
	printPath(path);
	
}
/**********TODO*********/
/*IDAN
* nextKnightPositions - V
* CreateNextPosList
* Modolaring board size

*/

/****************TESTS FUNCTIONS************************/
void testNextKNightPos() {
	chessPos pos = { 'A','1' };
	chessPosArray ans;
	chessPosArray*** validMovesBoard = validKnightMoves(); 
	ans = nextKnightPositions(validMovesBoard, pos);

}
void printPath(pathTree path)
{
	printPathRec(path.roots);
}
void printPathRec(treeNode* root)
{
	if (root->next_possible_positions != NULL) {
		printf("[%c%c] -->", (root->position)[0], (root->position)[1]);
		printPathRec(root->next_possible_positions->node);
	}
	else
		printf("[%c%c] --> NULL", (root->position)[0], (root->position)[1]); /*last one*/
}
/*Q3*/
pathTree findAllPossibleKnightPaths(chessPos* startingPosition) {
	pathTree path;
	path = CreatePathTree(*startingPosition);
	bool** visitsMatrix = CreateVisitsMatrix(BOARD_SIZE);
	chessPosArray*** validMovesBoard = validKnightMoves(); 
	updateVisitMatrix(visitsMatrix, path.roots->position);
	pathBuildRec(path.roots, validMovesBoard, visitsMatrix);

	return path;
}

void pathBuildRec(treeNode* root, chessPosArray*** validMovesBoard, bool ** visitsMatrix) {
	treeNodeListCell* curr;
	root->next_possible_positions = CreateNextPosList(visitsMatrix, nextKnightPositions(validMovesBoard, root->position));
	curr = root->next_possible_positions;

	while (curr != NULL) {
		updateVisitMatrix(visitsMatrix, curr->node->position);
		pathBuildRec(curr->node, validMovesBoard, visitsMatrix);
		curr = curr->next;
	}
	updateVisitMatrix(visitsMatrix, root->position); /*TODO */
}

treeNodeListCell* CreateNextPosList(bool ** visitsMatrix, chessPosArray allNextPositions) {
	treeNodeListCell* head = NULL;
	int i;
	for (i = 0; i < allNextPositions.size; i++)
	{
		if (!isVisited(visitsMatrix,allNextPositions.positions[i])) /*if there is a move*/
			insertDataToHeadList(head, (allNextPositions.positions)[i]);
	}
	return head;
}



/*return if pos was visited*/
bool isVisited(bool** visitsMatrix, chessPos pos) {
	return (visitsMatrix)[charToInt(pos[0])][charToInt(pos[1])];
}

chessPosArray nextKnightPositions(chessPosArray*** validMovesBoard, chessPos currPos) {
	return  *(*(*(validMovesBoard)+charToInt(currPos[0]))+charToInt(currPos[1]));

	//return  *(validMovesBoard)[charToInt(currPos[0])][charToInt(currPos[1])];
}

void updateVisitMatrix(bool** visitsMatrix, chessPos pos) {
	bool tmp = isVisited(visitsMatrix, pos);

	(visitsMatrix)[charToInt(pos[0])][charToInt(pos[1])] = !tmp;
}

bool** CreateVisitsMatrix(int size) {
	int i, j;
	bool** res = (bool**)malloc(size * sizeof(bool*));

	for (i = 0; i < size; i++)
		res[i] = (bool*)calloc(size, sizeof(bool)); /*all visits start on false*/
	return res;
}

void insertDataToHeadList(treeNodeListCell** oldHead, chessPos pos)
{
	/*treeNodeListCell* newHeadNode;
	CreateListCell(newHeadNode, pos);
	insertNodeToHeadList(newHeadNode, oldHead);
	*/
	treeNodeListCell* newHeadNode =	CreateListCellnotvoid(pos);
	insertNodeToHeadList(newHeadNode, oldHead);
}

void insertNodeToHeadList(treeNodeListCell* newHead, treeNodeListCell** oldHead){
	newHead->next = *oldHead;
	oldHead = &newHead; /*update the pointer to list head*/
}

pathTree CreatePathTree(chessPos pos) {

	pathTree path;
	path.roots = (treeNode*)malloc(sizeof(treeNode));
	checkAlloc(path.roots, "failed growing new roots");
	(path.roots->position)[0] = pos[0];
	(path.roots->position)[1] = pos[1];
	return path;
}

/*NOT IN USE*/
void CreateListCell(treeNodeListCell* head, chessPos pos) {
	head = (treeNodeListCell*)malloc(sizeof(treeNodeListCell));
	checkAlloc(head, "failed growing new head to list");

	head->node = (treeNode*)malloc(sizeof(treeNode));
	checkAlloc(head->node, "failed growing root");

	*head->node->position = pos;
}

/*IN USE*/
treeNodeListCell* CreateListCellnotvoid(chessPos pos) {
	treeNodeListCell* head = (treeNodeListCell*)malloc(sizeof(treeNodeListCell));
	checkAlloc(head, "failed growing new head to list");

	head->node = (treeNode*)malloc(sizeof(treeNode));
	checkAlloc(head->node, "failed growing root");

	chessPosSetter(&head->node->position, pos);
	//*head->node->position = pos;
	return head;
}
