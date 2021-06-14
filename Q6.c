/*QueensGambit Q6 */

#include "Q6.h"
int checkAndDisplayPathFromFile(char* file_name) {
    int size, res = 3; /*any other case*/
    chessPosList* fileList;
    FILE* fp = fopen(file_name, "rb"); /*check open menualy to return -1*/
    if (!fp) {
        fprintf(stderr, "Error opening file: %s\n", file_name);
        return -1; /*incase there is no file*/
    }

    fileList = createListFromFile(fp, &size);

    if (!checkValidKnightPath(fileList))
        return 1;
    else {
        res = 2; /* found valid path */
        display(fileList);
        if (listSize(fileList->head) < BOARD_SIZE * BOARD_SIZE)
            res = 3;
    }
    fclose(fp);
    return res;
}

chessPosList* createListFromFile(FILE* fp, int* size) {

    int fileSize, i, nameLen, maskCounter;
    int currFileCorsur;
    short listSize;

    bool numOrLeter = true; /*true - letter | false - number*/

    chessPos pos;
    Byte reader, lastByte;
    chessPosList* fileList = (chessPosList*)malloc(sizeof(chessPosList));
    checkAlloc(fileList, "failed to allocate list from file");
    makeEmptyList(fileList);

    fseek(fp, 0, SEEK_END);
    fileSize = ftell(fp);
    rewind(fp);

    /*
    chessPos: E3 C4 A3 B1 ||| D2

    Bin File: 100,010,01 0,011,000,0 10,001,000, ||| 011,001,00
    in binary: 89 30 88 64


    100,010,01
    100,000,00
    00000100
    */

    Byte masks[10] = { 0b11100000, 0b00011100,
                       0b00000011, 0b10000000, 0b01110000,
                       0b00001110, 0b00000001, 0b11000000,
                       0b00111000, 0b00000111 };
    int shiftByMask[10] = { 5,2,
                            0,7,4,
                            1,0,6,
                            3,0 };
    /*jumps to the start of the list*/
    fread(&listSize, sizeof(short), 1, fp);
    currFileCorsur = ftell(fp);

    for (i = 0, maskCounter = 0; i < (int)listSize; maskCounter++) {
        if (maskCounter == 10)
            maskCounter = 0;
        if (maskCounter == 0)
            fread(&reader, sizeof(Byte), 1, fp);

        if (maskCounter <= 1 || maskCounter >= 8) {
            if (numOrLeter) {
                pos[0] = IntToCharLetter((int)((reader & masks[maskCounter]) >> shiftByMask[maskCounter]));
                numOrLeter = false;
            }
            else {
                pos[1] = IntToCharNum((int)((reader & masks[maskCounter]) >> shiftByMask[maskCounter]));
                numOrLeter = true;
            }
        }

        else {  /*maskCounter = 2,3,4,5,6,7*/
            if (maskCounter == 2) {
                lastByte = reader;
                fread(&reader, sizeof(Byte), 1, fp);

                lastByte = (lastByte & masks[maskCounter]) << 1;

                pos[0] = IntToCharLetter((int)(lastByte | ((reader & masks[++maskCounter]) >> shiftByMask[maskCounter++]))); /*shiftByMask supposed to be 7*/
                pos[1] = IntToCharNum((int)((reader & masks[maskCounter]) >> shiftByMask[maskCounter]));
            }

            if (maskCounter == 5) {

                pos[0] = IntToCharLetter((int)((reader & masks[maskCounter]) >> shiftByMask[maskCounter++]));

                lastByte = reader;
                lastByte = (lastByte & masks[maskCounter]) << 2; /*0000 000b  => 0000 0b00  */
                fread(&reader, sizeof(Byte), 1, fp);

                pos[1] = IntToCharNum((int)(lastByte | ((reader & masks[++maskCounter]) >> shiftByMask[maskCounter]))); /*shiftByMask supposed to be 6*/
                /* lastByte = 0000 0b00  ||| reader = bbbb bbbb & 1100 0000 => bb00 0000 >> 6 => 0000 00bb
                   lastByte | reader = 0000 0bbb */
            }
        }
        if (maskCounter == 1 || maskCounter == 4 || maskCounter == 7 || maskCounter == 9) {
            addNewTailToListPos(fileList, Initiate((pos)));
            i++;
        }
    }
    *size = i;

    return fileList;
}

bool checkValidKnightPath(chessPosList* lst) {
    chessPosCell* prev, * curr;
    prev = lst->head;
    curr = prev->next;

    bool flag = true;
    int** boardValues = createBoard();
    removeExcessCells(lst, boardValues);
    for (prev, curr; curr != NULL && flag; curr = curr->next, prev = prev->next) {
        if (!validSingleMove(prev->position, curr->position))
            flag = false;
    }
    freeBoard(boardValues);
    return flag;
}

bool validSingleMove(chessPos a, chessPos b) {
    int letterDistance = abs(a[0] - b[0]);
    int NumberDistance = abs(a[1] - b[1]);

    if ((letterDistance == 1 || letterDistance == 2) && (NumberDistance == 1 || NumberDistance == 2)
        && letterDistance != NumberDistance && letterDistance + NumberDistance == 3)
        return true;

    return false;
}