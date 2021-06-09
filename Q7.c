/*Dor And the Mighty Idan Q7 Bitch*/

#pragma once
#include "Q7.h"

void menu() {

	int userChoice;
	chessPos userPos;
	pathTree userPath;
	chessPosList* fullPath ;
	//makeEmptyList(fullPath); /*TODO*/
	userPos[0] = userPos[1] = NOT_DEFINED;
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
			do {
				printf("Please enter valid params: <A-H> <1-8> : ");
				getchar();
				scanf("%c %c", &userPos[0], &userPos[1]);
			} while (!isValidInput(userPos[0], userPos[1]));
		
			break;

		case 2:
			if (userPos[0] != NOT_DEFINED) {
				userPath = findAllPossibleKnightPaths(&userPos);/*TODO check if works 100%*/
				printf("\ndone bulding userPath\n");
			}
			else
				printf("please enter a starting knight position before choosing this option\n");
			break;

		case 3:
			
			if (userPos[0] != NOT_DEFINED) {
				if (!userPath.roots)
					userPath = findAllPossibleKnightPaths(&userPos);/*TODO check if works 100%*/

				fullPath = findKnightPathCoveringAllBoard(&userPath); /*TODO check if works 100%*/
				freePath(&userPath);
				printf("\ndone bulding fullPath\n");
			}
			else
				printf("please enter a starting knight position before choosing this option\n");
			break;

		case 4:
			if (userPos[0] != NOT_DEFINED) {
				saveListBinFile("testQ5.bin", fullPath);
				freeListCell(fullPath);
			}
			else
				printf("please enter a starting knight position before choosing this option\n");
			break;
		case 5:
			checkAndDisplayPathFromFile("testQ5.bin");
			break;
		case 6:
			printf("GoodBye..");
			exit(0); 

		default:
			printf("Please choose number between 1-6\n"); 
			break;
		}
	} while (userChoice != 6); 


}
