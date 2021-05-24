/*Dor And the Mighty Idan Q7 Bitch*/
#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"
#include "Q4.h"
#include "Util.h"

void menu()
{
	int userChoice;
	chessPos userPos;
	pathTree userPath;
	chessPosList* fullPath;
	/*TODO Q5 Q6*/
	FILE* knightPath;

	printf("Welcome to QueensGambit \n");
	/*TODO cls*/
	do
	{
		printf("Choose option from the following menu: \n");
		printf("1.\tEnter a knight's starting position. \n");
		printf("2.\tCreate all possible knight paths. \n");
		printf("3.\tFind a knight path covering all board. \n");
		printf("4.\tSave knight path covering all board to file. \n");
		printf("5.\tLoad and display path from file. \n");
		printf("6.\tExit. \n"); 
		scanf("%d", &userChoice);

		switch (userChoice) {
		case 1:
			printf("Enter params: <A-E> <1-8> : ");
			scanf("%c %c", &userPos[0], &userPos[1]);
			break;

		case 2:
			userPath = option2(userPos);
			break;

		case 3:
			fullPath = findKnightPathCoveringAllBoard(&userPath); /*TODO check if works 100%*/
			break;

		case 4:
			/*TODO Q5*/
			break;
		case 5:
			/*TODO Q6*/
			break;
		case 6:
			printf("GoodBye..");
			exit(0); /*TODO exit?*/

		default:
			printf("Please choose number between 1-6 ya bish"); /*TODO ya bish*/
			break;
		}

	} while (userChoice != 6); /*TODO while true coz case 6 takes us out*/

	freePath(&userPath);
	if (fullPath) {
		display(fullPath); /*TODO change*/
		freeListCell(fullPath);
	}
	/*TODO free fullPath*/
}
pathTree option2(chessPos pos) {
	pathTree path;
	chessPosList* fullPath;
	path = findAllPossibleKnightPaths(&pos);
	return path;
}