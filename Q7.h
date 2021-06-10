/*Q7 header*/
#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include <conio.h>
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"
#include "Q4.h"
#include "Q5.h"
#include "Q6.h"
#include "Util.h"

#define NOT_DEFINED -1

void menu();

void freeForAll(pathTree* userPath, chessPosList* fullPath, char* filename);
