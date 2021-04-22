#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>

#define BOARD_END 0
#define BOARD_SIZE 10
#define TRUE 1
#define FALSE 0

char board[BOARD_SIZE][BOARD_SIZE];
char uboard[BOARD_SIZE][BOARD_SIZE]; 

void setupMines();
void buildUserBoard();
void printBoard();
void printUserBoard();
void getInfo();
int findMines(int row, int column);
int mineSweep(int row, int column);
void setupGame();
int winCheck();
void win();
void loss();
