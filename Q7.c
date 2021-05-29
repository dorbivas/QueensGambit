/*Dor And the Mighty Idan Q7 Bitch*/

#pragma once
#include "Q7.h"

void menu()
{
	int userChoice;
	chessPos userPos;
	pathTree userPath;
	chessPosList* fullPath ;
	//makeEmptyList(fullPath); /*TODO*/
	userPath.roots = NULL; 

	/*TODO Q5 Q6*/
	FILE* knightPath;

	printf("Welcome to QueensGambit \n");
	do
	{
		//system("cls"); /*TODO cls*/
		printf("Choose option from the following menu: \n");
		printf(" 1.\tEnter a knight's starting position. \n");
		printf(" 2.\tCreate all possible knight paths. \n");
		printf(" 3.\tFind a knight path covering all board. \n");
		printf(" 4.\tSave knight path covering all board to file. \n");
		printf(" 5.\tLoad and display path from file. \n");
		printf(" 6.\tExit. \n"); 
		scanf("%d", &userChoice);

		switch (userChoice) {
		case 1:
			do
			{
				printf("Please enter valid params: <A-H> <1-8> : ");
				getchar();
				scanf("%c %c", &userPos[0], &userPos[1]);
			} while (!isValidInput(userPos[0], userPos[1]));
		
			break;

		case 2:
			userPath = findAllPossibleKnightPaths(&userPos);/*TODO check if works 100%*/
			printf("\ndone bulding userPath\n");
			break;

		case 3:
			if (userPath.roots)	{
				fullPath = findKnightPathCoveringAllBoard(&userPath); /*TODO check if works 100%*/
				printf("\ndone bulding fullPath\n");
				if (fullPath) {
					display(fullPath);
					//Sleep(1000); /*TODO*/
				}
				else
					printf("\nfking empty bish\n"); /*TODO CHANGE*/
			}
			else
				printf("\nPlease build a path before.\n");
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
			printf("Please choose number between 1-6 ya bish\n"); /*TODO ya bish*/
			break;
		}

	} while (userChoice != 6); /*TODO while true coz case 6 takes us out*/

	//freePath(&userPath);
	//if (fullPath) {
	//	display(fullPath); /*TODO change*/
	//	freeListCell(fullPath);
	//}
	/*TODO free fullPath*/
}
