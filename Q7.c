/*QueensGambit Q7 */

#pragma once
#include "Q7.h"

void menu() {

	int userChoice;
	chessPos userPos;
	pathTree userPath;
	chessPosList* fullPath = NULL;
	userPos[0] = userPos[1] = NOT_DEFINED;
	userPath.roots = NULL; 
	FILE* knightPath;
	char* filename = NULL;

	printf("Welcome to QueensGambit \n");
	do	{
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
				userPath = findAllPossibleKnightPaths(&userPos);
				printf("\ndone bulding userPath\n");
			}
			else
				printf("please enter a starting knight position before choosing this option\n");
			break;

		case 3:
			
			if (userPos[0] != NOT_DEFINED) {
				if (!userPath.roots)
					userPath = findAllPossibleKnightPaths(&userPos);

				fullPath = findKnightPathCoveringAllBoard(&userPath);
				if (fullPath)
					printf("\ndone bulding fullPath\n");
				else
					printf("no full path was found\n");
				freePath(&userPath);
			}
			else
				printf("please enter a starting knight position before choosing this option\n");
			break;

		case 4:
			if (userPos[0] != NOT_DEFINED) {
				if (fullPath) {
					filename = getFileName();
					saveListBinFile(filename, fullPath);
					freeListCell(fullPath);
					printf("path was saved to %s\n", filename);
					free(filename);
				}
				else
					printf("no path was sent\n");
			}
			else
				printf("please enter a starting knight position before choosing this option\n");
			break;
		case 5:
			filename = getFileName();
			checkAndDisplayPathFromFile(filename);
			free(filename);
			
			break;
		case 6:
			printf("GoodBye..");
			freeForAll(&userPath, fullPath, filename);
			exit(0); 

		default:
			printf("Please choose number between 1-6\n"); 
			break;
		}
	} while (userChoice != 6); 
}

void freeForAll(pathTree* userPath, chessPosList* fullPath,char* filename) {
	if((*userPath).roots->next_possible_positions)
		freePath(userPath);
	if(fullPath)
		freeListCell(fullPath);
	if(filename)
		free(filename);
}