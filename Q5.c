/*QueensGambit Q5 */

#define _CRT_SECURE_NO_WARNINGS
#include "Q5.h" 

Byte posToByte(char pos) { /*gets only half pos and translate to bits*/
	return (Byte)charToChessValue(pos);
}

void saveListBinFile(char* file_name, chessPosList* pos_list) {
	chessPosCell* curr = pos_list->head;
	FILE* fpListOut = fopen(file_name, "wb+");
	if (!fpListOut) {
		fprintf(stderr, "enter valid name followed by \".bin\" %s\n", file_name);
		return; /*incase the name is not valid*/
	}
	short listLen = listSize(pos_list->head); 
	fwrite(&listLen, sizeof(short), 1, fpListOut); /*writing the size of the list*/

	while (curr) {
		if (listLen >= 4) {
			insertBytes(&curr, 4, fpListOut);
			listLen -= 4;
		}
		else if (listLen == 3) {
			insertBytes(&curr, 3 ,fpListOut);
			listLen -= 3;
		}
		else if (listLen == 2) {
			insertBytes(&curr, 2 , fpListOut);
			listLen -= 2;
		}
		else if (listLen == 1) {
			insertBytes(&curr, 1, fpListOut);
			listLen--;
		}
	}
	fclose(fpListOut);
}

short listSize(chessPosCell* curr) {
	short res = 0;
	while (curr) {
		curr = curr->next;
		res++;
	}
	return res;
}

void insertBytes(chessPosCell** curr, short amount, FILE* fp) {
	int i;
	Byte temp;
	Byte* b = (Byte*)malloc(sizeof(Byte) * (int)amount);
	checkAlloc(b, "failed to allocate Byte array");

	for (i = 0; i < amount; i++ , (*curr) = (*curr)->next) 
		b[i] = createChessPosByte(*curr);


	/*normalizing the bytes by definition*/
	switch (amount){
	case 2:
		init2PosBytes(b);
		break;
	case 3:
		init3PosBytes(b);
		break;
	case 4:
		init4PosBytes(b);
 		amount--;
		break;

	default:
		break;
	}
	fwrite(b, sizeof(Byte), amount, fp);
	fflush(fp);
}

void init2PosBytes(Byte* b) {
	Byte temp;
	temp = b[1];

	b[1] = b[1] << 2;
	temp = temp >> 6;
	b[0] |= temp;
}

void init3PosBytes(Byte* b) {
	Byte temp;

	init2PosBytes(b);
	temp = b[2];
	temp = temp >> 4;
	b[2] = b[2] << 4;
	b[1] |= temp;
}

void init4PosBytes(Byte* b) {
	init3PosBytes(b);
	b[3] = b[3] >> 2;
	b[2] |= b[3];
}

Byte createChessPosByte(chessPosCell* curr) {
	Byte pos0, pos1;
	pos0 = posToByte(curr->position[0]);
	pos1 = posToByte(curr->position[1]);
	pos0 = ((pos0 << 3) | pos1) << 2;
	return pos0;
	/*proccess
	pos0 = pos0 << 3;
	pos0 = pos0 | pos1;
	pos0 = pos0 << 2;*/
}