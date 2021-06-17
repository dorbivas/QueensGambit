/*QueensGambit Q4 */

#define _CRT_SECURE_NO_WARNINGS
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"
#include "Q4.h" /*
change includs*/

#define MAX_STEPS 25 /*BOARD_SIZE ^ 2*/ 

chessPosList* findKnightPathCoveringAllBoard(pathTree* path_tree){
	int lvls = 1;
	chessPosList* resList = (chessPosList*)malloc(sizeof(chessPosList));
	treeNodeListCell* curr = path_tree->roots->next_possible_positions; /*curr list*/
	int loopCntr;
	loopCntr = 0;
	makeEmptyList(resList);
	addNewTailToListPos(resList, path_tree->roots->position);
	finedFullPathRec(curr, &resList, &lvls);
	reverseList(resList);

	if (lvls == MAX_STEPS)
		return resList;
	return NULL; /*incase thers no path that covers the board*/
}

/*lvls == 1 at the start lst has one node, lvl is the rank in the tree*/
void finedFullPathRec(treeNodeListCell* currListHead, chessPosList** lstPtr, int* lvls) {
	if (*lvls < MAX_STEPS && currListHead) {
		if (currListHead->node) {
			(*lvls)++;
			addNewHeadToListPos(*lstPtr, currListHead->node->position);
			finedFullPathRec(currListHead->node->next_possible_positions, lstPtr, lvls);
		}

		if (*lvls < MAX_STEPS) {
			removeHeadOfList(*lstPtr);
			(*lvls)--; /*last head pos failed going up*/
			if (currListHead->next) {
				finedFullPathRec(currListHead->next, lstPtr, lvls);
			}
		}
	}

}


