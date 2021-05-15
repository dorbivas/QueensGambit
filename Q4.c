/*Dor And the Mighty Idan Q4 Bitch*/

#define _CRT_SECURE_NO_WARNINGS
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"
#include "Q4.h" /*TODO change includs*/

#define MAX_MOVES 24 /*TODO universal ? 5X5 - 1*/

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



/* pathtree
	* get curr list 
	* run all lists in rec helper from bottom (maybe count ranks tree with most ranks)
	* build posList from CellList
	* use list leng func to compere if MAX MOVES is acchived (board is coverd)
	* findKnightPathCoveringAllBoardRec()
*/