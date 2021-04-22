#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "func.h"

int main(int argc, char const *argv[]) {
    setupGame();
    return 0;
}

void welcome(){ 
    printf("\nHi, welcome to Minesweeper!\n\n");
}

void printBoard(){

    int column, row;

    for(column = 0; column < BOARD_SIZE ; column++)
        printf(" %d ", column);
    printf("\n");

    for(row = 0; row < BOARD_SIZE; row++)
    {
        for(column = 0; column < BOARD_SIZE; column++)
            printf(" %c ", board[row][column]);
        if(row >= 0 &&  row <= BOARD_SIZE -1)
            printf("%d", row);
        printf("\n");
    }
}

void buildUserBoard(){
    int column, row;

    for(column = 0; column < BOARD_SIZE; column++)
        for(row = 0; row < BOARD_SIZE; row++)
            uboard[column][row] = '-';
}
void printUserBoard(){
    int column, row;

    system("cls");
    for(column = 0; column < BOARD_SIZE ; column++)
        printf(" %d ", column);
    printf("\n\n");

    for(column = 0; column < BOARD_SIZE ; column++)
    {
        for(row = 0; row < BOARD_SIZE; row++)
        {
            printf(" %c ", uboard[column][row]);
        }
        if(column >= 0 &&  column <= BOARD_SIZE  )
            printf("   %d", column);
        printf("\n");
    }
}

void setupMines(){

    int column, row;

    for(column = 0; column < BOARD_SIZE ; column++){
        for (row = 0; row < BOARD_SIZE ; row++)
            board[column][row] = '-';
    }

    srand(time(0));
    for(row = 0; row < BOARD_SIZE ; row++){
        int random = rand() % (BOARD_SIZE );
        board[random][row] = 'M';
    }
}

int findMines(int row, int column){

     int mines = 0;

    if(board[row - 1][ column] == 'M')
        mines++;
    if(board[row + 1][ column] == 'M')
        mines++;
    if(board[row][ column - 1] == 'M')
        mines++;
    if(board[row][ column + 1] == 'M')
        mines++;

    if(board[row - 1][ column + 1] == 'M')
        mines++;
    if(board[row - 1][ column - 1] == 'M')
        mines++;
    if(board[row + 1][ column + 1] == 'M')
        mines++;
    if(board[row + 1][ column - 1] == 'M')
        mines++;

    return mines;
}

void setupGame(){

    int xposition, yposition;

    getInfo();
    system("pause");
    setupMines();
    buildUserBoard();
    printUserBoard();

    for(;;){
    do{ printf("\nEnter the row: ");
        scanf("%d",&xposition);
        printf("Enter the column: ");
        scanf("%d",&yposition);
        printf("\n");
        } while(xposition < 0 || xposition > BOARD_SIZE -1 
            || yposition < 0 || yposition > BOARD_SIZE -1 );

        if (board[xposition][yposition] == 'M'){
            printf("You have hit a mine!\n\n");
            printBoard();
            loss();
        }
        else {
            mineSweep(xposition, yposition);
    }
    printUserBoard();
    }
}

int winCheck(){

    int column, row;

    for(column = 1; column < BOARD_SIZE - 1; column++)
        for(row = 1; row < BOARD_SIZE - 1; row++) {
            if(uboard[column][row] == '-' && board[column][row] != 'M')
                return FALSE;
        }

    return TRUE;
}

int mineSweep(int column, int row){

    int nearbymines = 0;

    if( row < 0 || row >= BOARD_SIZE || column < 0 || column >= BOARD_SIZE || uboard[column][row] != '-'){
        return 0;
    }
    nearbymines = findMines(column, row);
    uboard[column][row] = (char)(((int)'0') + nearbymines);
    if (nearbymines < 1){
        mineSweep(column, row -1);
        mineSweep(column+1, row-1);
        mineSweep(column+1, row);
        mineSweep(column+1, row+1);
        mineSweep(column, row+1);
        mineSweep(column-1, row+1);
        mineSweep(column-1, row);
        mineSweep(column-1, row-1);
    }
    return BOARD_END;
}

void winner(){

    char choice;

    printf("Congratulations!!!!! \n Another One?:D (Y/N)--> ");
    scanf("%c", &choice);

    if (toupper(choice) == 'y'){
        system("cls");
    }
    else
        exit(99);
}

void loss(){

    char choice;

    scanf("%c", &choice);
    printf("I'm sorry, you lost:(!\n\nAgain?:D (Y/N)");
    scanf("%c", &choice);
    if (toupper(choice) == 'Y'){
        system("cls");
        setupGame();
    }

    else {
        printf("\nThanks for playing, bye! \n\n ");
        exit(0);
    }
}