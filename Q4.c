/*Dor And the Mighty Idan Q4 Bitch*/

#define _CRT_SECURE_NO_WARNINGS
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"

#define MAX_MOVES 24 /*5X5 - 1*/

chessPosList* findKnightPathCoveringAllBoard(pathTree* path_tree)
{
	int lvls = 1;
	chessPosList* res = (chessPosList*)malloc(MAX_MOVES * sizeof(chessPosList));
	treeNode* root = path_tree->roots;
	treeNodeListCell* curr = root->next_possible_positions; /*curr list*/

	if (root != NULL)/*empty? TODO*/
		addNewTailToListPos(res,root->position);

	findKnightPathCoveringAllBoardRec(root, curr, &res , &lvls);
	if (lvls == MAX_MOVES)
		return res;
	return NULL; /*incase thers no path that covers the board*/

}

void findKnightPathCoveringAllBoardRec(treeNode* root, treeNodeListCell* currListHead, chessPosList** res , int* lvls) {
	chessPosCell** prevListTail;
	if (currListHead->node == NULL){
		if (lvls == MAX_MOVES){
			return res;
		}
		else
			return;
	}

	if (lvls != MAX_MOVES) {
		while (currListHead) {

			if (currListHead->node) { /*if we go to a lower rank we add to new tail */
				addNewTailToListPos(*res, currListHead->node->position);
				*prevListTail = (*res)->tail;
				*lvls++;
				findKnightPathCoveringAllBoardRec(currListHead->node, currListHead, res, lvls);
			}
			if (currListHead->next)  /*if we travel to the sides of the list replace  */
			{
				*prevListTail = (*res)->tail; /*TODO not sure where to put it and if needed?*/
				replaceTailInListPos(*res, createNewListNode(currListHead->node->position, NULL), *prevListTail);
				findKnightPathCoveringAllBoardRec(currListHead, currListHead->next, res, lvls);
			}
			*lvls--;

		}
	}

}

void addNewTailToListPos(chessPosList* lst, chessPos newTailPos) {
	chessPosCell* newTail;
	newTail = createNewListNode(newTailPos, NULL);
	insertNodeToEndList(lst, newTail);
}

void replaceTailInListPos(chessPosList* lst, chessPosCell* newTail,chessPosCell* oldTail) {
	chessPosCell* tmp;
	if (isEmptyList(lst)) {
		lst->head = lst->tail = newTail;
	}
	else {
		tmp = lst->tail;
		lst->tail = newTail;
		oldTail->next = newTail;
		free(tmp);
	}
	newTail->next = NULL;
}


void makeEmptyList(chessPosList* lst){
	lst->head = lst->tail = NULL;
}

bool isEmptyList(chessPosList* lst){
	return (lst->head == NULL);
}

chessPosCell* createNewListNode(chessPos pos, chessPosCell* next){
	chessPosCell* res;
	res = (chessPosCell*)malloc(sizeof(chessPosCell));
	chessPosSetter(&res->position, pos);
	res->next = next;
	return res;
}

void insertNodeToEndList(chessPosList* lst, chessPosCell* tail)
{
	if (isEmptyList(lst)) {
		lst->head = lst->tail = tail;
	}
	else {
		lst->tail->next = tail;
		lst->tail = tail;
	}
	tail->next = NULL;
}

/* pathtree
	* get curr list 
	* run all lists in rec helper from bottom (maybe count ranks tree with most ranks)
	* build posList from CellList
	* use list leng func to compere if MAX MOVES is acchived (board is coverd)
	* findKnightPathCoveringAllBoardRec()
*/