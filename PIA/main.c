/* 

Hi friends and teacher, this is my game, the UANL MAZE
to play this game you should use the gdb online compiler,
by adding this 3 files in the compiler
-main.c
-maze.c
-header.c

Then you can run the game and enjoy it:)

*/

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int cls = 0;
    title();
    
    printf("Hi Player!\n");
    printf("Now you're about to play a laberythm, and the rules are simple!\n");
    printf("-You move with w,a,s,d as in a normal game!\n");
    printf("-Your only goal is to find a way out to win this game!\n\n");
    printf("Best of lucks!\n\n");
 
    maze();
}

