/*Dor And the Mighty Idan Util Lib Bitch 315557850*/
#define _CRT_SECURE_NO_WARNINGS
#include "Util.h"

/*Q1 util*/
/*TODO CHANGE INT TO CHAR SIGNATURE*/
int IntToCharNum(int num) {
	return '1' + num;
}
int IntToCharLetter(int num) {
	return 'A' + num;
}

void freeChessBoard(chessPosArray*** board) {
	int i, j;
	for (i = 0; i < BOARD_SIZE; i++) {
		for (j = 0; j < BOARD_SIZE; j++)
			free(board[i][j]);
		free(board[i]);
	}
	free(board);
}

/*Q2 util*/
void printRoofNumbers(){
	int i;
	printf("\t");

	for ( i = 1; i < BOARD_SIZE + 1; i++)
		printf("%3d   ", i);
	printf("\n\n");
}

void printBoard(int boardValues[BOARD_SIZE][BOARD_SIZE]) {

	printRoofNumbers(BOARD_SIZE);
	for (int row = 0; row < BOARD_SIZE; row++) {
		printf("%3c    |", 'A' + row); /* columns numbers*/
		for (int col = 0; col < BOARD_SIZE; col++) {
			if (boardValues[row][col] == 0)
				printf("     |");
			else
				printf("%3d  |", boardValues[row][col]);
		}
		printf("\n");
	}
	printf("\n");
}

bool comparePos(chessPos a, int row, int col) {
	return ((charToInt(a[0]) == row) && (charToInt(a[1]) == col));
}

int charToInt(char ch) { /*TODO CHANGE NAME*/
	if (ch >= 'A' && ch <= 'Z')
		return (ch - 'A');

	return ch - '1';
}

void checkAlloc(void* ptr, char* msg)
{
	if (!ptr)
	{
		printf("Allocation failed: %s", msg);
		exit(1);
	}
}

void chessPosSetter(chessPos* dest, chessPos src) {
	(*dest)[0] = src[0];
	(*dest)[1] = src[1];
}

/*Q4 util*/
void addNewTailToListPos(chessPosList* lst, chessPos newTailPos) {
	chessPosCell* newTail;
	newTail = createNewListNode(newTailPos, NULL);
	insertNodeToEndList(lst, newTail);
}

void updateListPosTail(chessPosList* lst, chessPos newTailPos) {
	chessPosSetter(&(lst->tail->position), newTailPos);
}

void addNewHeadToListPos(chessPosList* lst, chessPos newTailPos) {
	chessPosCell* newHead = createNewListNode(newTailPos, NULL);
	insertNodeToStartList(lst, newHead);
}

void insertNodeToStartList(chessPosList* lst, chessPosCell* newHead) {
	if (isEmptyList(lst)) {
		lst->head = lst->tail = newHead;
	}
	else {
		newHead->next = lst->head;
		lst->head = newHead;
	}
}

void removeHeadOfList(chessPosList* lst) {/*behead*/
	chessPosCell* temp = lst->head;
	lst->head = lst->head->next;
	free(temp);
}

void reverseList(chessPosList* lst) {

	chessPosCell* prev, * curr, * next;
	prev = NULL;
	if (!isEmptyList(lst)) {

		curr = lst->head;
	
		while (curr) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
	
		curr = lst->head;
		lst->head = lst->tail;
		lst->tail = curr;
	}

}

void replaceTailInListPos(chessPosList* lst, chessPosCell* newTail, chessPosCell* oldTail) {
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

void makeEmptyList(chessPosList* lst) {
	lst->head = lst->tail = NULL;
}

bool isEmptyList(chessPosList* lst) {
	return (lst->head == NULL);
}

chessPosCell* createNewListNode(chessPos pos, chessPosCell* next) {
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

void freeListCell(chessPosList* lst) {
	chessPosCell* temp = lst->head;
	chessPosCell* curr = temp->next;
	while (curr) {
		free(temp);
		temp = curr;
		curr = temp->next;
	}
	free(temp);
}

/*Q5 util*/
void checkFileOpen(FILE* fp, char* msg){
	if (!fp){
		fprintf(stderr, "Error opening file: %s\n", msg);
		exit(1);
	}
}
/*Q7 util*/
bool isValidInput(char pos1, char pos2) {
	return(pos1 >= 'A' && pos1 <= 'E' && pos2 >= '1' && pos2 <= '8');
}