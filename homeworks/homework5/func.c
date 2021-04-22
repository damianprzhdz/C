#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include "func.h"


typedef struct playerInfo{
    char name[15];
    int age;
    int time;
} Player;
//^to be added later for more marks???
/*typedef struct position{
    int xpos;
    int ypos;
} boardPosition;*/

void getInfo(){ // Hope to expand this function to write names and ages to a file, also want to
                //write times but not sure how to find the time taken to play the game.


    Player p1;
    printf("Please enter your name: ");
    scanf("%s", p1.name);
    printf("Please enter your age: ");
    scanf("%i", &p1.age);
    printf("\nHi %s, welcome to Minesweeper!\n\n",p1.name);


}


void printBoard(){


    int column, row;


    // Print the top row of numbers.
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


    // Set all elements in the board to '-'
    for(column = 0; column < BOARD_SIZE; column++)
        for(row = 0; row < BOARD_SIZE; row++)
            uboard[column][row] = '-';
}
void printUserBoard(){
    int column, row;


    system("cls");
    // Print the top row of numbers.
    for(column = 0; column < BOARD_SIZE ; column++)
        printf(" %d ", column);
    printf("\n\n");


    // Print the actual board with column numbers.
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




// Setting up mines within the board, represented by M
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
//Finds mines in adjacent locations to user selection
int findMines(int row, int column){


     int mines = 0;


    // Check up, down, left, right.
    if(board[row - 1][ column] == 'M')
        mines++;
    if(board[row + 1][ column] == 'M')
        mines++;
    if(board[row][ column - 1] == 'M')
        mines++;
    if(board[row][ column + 1] == 'M')
        mines++;




    // Check all diagonal directions
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


//Sets up board and prints intial board for user input.
void setupGame(){


    int xpos, ypos;


    getInfo();
    system("pause");
    setupMines();
    buildUserBoard();
    printUserBoard();


    for(;;){
    do{ printf("\nEnter the row: ");
        scanf("%d",&xpos);
        printf("Enter the column: ");
        scanf("%d",&ypos);
        printf("\n");
        } while(xpos < 0 || xpos > BOARD_SIZE -1 || ypos < 0 || ypos > BOARD_SIZE -1 );


        if (board[xpos][ypos] == 'M'){
            printf("You have hit a mine!\n\n");
            printBoard();
            loss();
        }
        else
            mineSweep(xpos, ypos);


    printUserBoard();
    }
    
}
//Checks to see if a loss has occurred
void loss(){


    char choice;


    scanf("%c", &choice);
    printf("You have lost!\n\nWould you like to play again? (Y/N)--> ");
    scanf("%c", &choice);
    if (toupper(choice) == 'Y'){
        system("cls");
        setupGame();
    }


    else
        printf("\nThanks for playing, bye! \n\n ");
        exit(0);
}


//Checks to see if a win has occurred
int winCheck(){


    int column, row;


    for(column = 1; column < BOARD_SIZE - 1; column++)
        for(row = 1; row < BOARD_SIZE - 1; row++) {
            if(uboard[column][row] == '-' && board[column][row] != 'M')
                return FALSE;
        }


    return TRUE;
}


void win(){


    char choice;


    printf("Congratulations, you have won! \nWould you like to start another game? (Y/N)--> ");
    scanf("%c", &choice);


    if (toupper(choice) == 'y'){
        system("cls");
    }
    else
        exit(99);
}


