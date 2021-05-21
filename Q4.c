/*Dor And the Mighty Idan Q4 Bitch*/

#define _CRT_SECURE_NO_WARNINGS
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"
#include "Q4.h" /*TODO change includs*/

#define MAX_STEPS 25 /*BOARD_SIZE ^ 2*/ 

chessPosList* findKnightPathCoveringAllBoard(pathTree* path_tree){
	int lvls = 1;
	chessPosList* resList = (chessPosList*)malloc(sizeof(chessPosList));
	treeNodeListCell* curr = path_tree->roots->next_possible_positions; /*curr list*/
	int loopCntr;
	loopCntr = 0;
	makeEmptyList(resList);
	addNewTailToListPos(resList, path_tree->roots->position);

	//findKnightPathCoveringAllBoardRec(root, curr, &res , &lvls);
	rec(curr, &resList, &lvls, &loopCntr);
	reverseList(resList);
	if (lvls == MAX_STEPS)
		return resList;
	return NULL; /*incase thers no path that covers the board*/

}


/*lvls == 1 at the start lst has one node*/
void rec(treeNodeListCell* currListHead, chessPosList** lstPtr, int* lvls, int* recCntr) {
	(*recCntr)++;
	if (*lvls < MAX_STEPS && currListHead) {
		if (currListHead->node) {
			(*lvls)++;
			addNewHeadToListPos(*lstPtr, currListHead->node->position);
			rec(currListHead->node->next_possible_positions, lstPtr, lvls, recCntr);
		}

		if (*lvls < MAX_STEPS) {
			removeHeadOfList(*lstPtr);
			(*lvls)--;
			if (currListHead->next) {
				rec(currListHead->next, lstPtr, lvls, recCntr);
			}
		}
	}

}


