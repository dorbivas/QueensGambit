
/*Dor And the Mighty Idan Q4 Bitch*/

#define _CRT_SECURE_NO_WARNINGS
#include "Q5.h" 

Byte posToByte(char pos) { /*gets only half pos and translate to bits*/
	return (Byte)charToInt(pos);
}

void saveListBinFile(char* file_name, chessPosList* pos_list) {
	chessPosCell* curr = pos_list->head;
	FILE* fpListOut = fopen(file_name, "wb+");

	short listLen = listSize(pos_list); 
	fwrite(&listLen, sizeof(short), 1, fpListOut);

	while (curr) {
		if (listLen >= 3)
			insert3Bytes(&curr , fpListOut);
		else if (listLen == 2)
			insert2Bytes(&curr, fpListOut);
		else if (listLen == 1)
			insert1Bytes(&curr, fpListOut);
		listLen = listSize(curr);
	}
}
