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

void title(){
printf("#     #  #######  #     #   #         #     #  #######  #######  ####### \n");
printf("#     #  #     #  ##    #   #         ##   ##  #     #       #   #       \n");
printf("#     #  #     #  # #   #   #         # # # #  #     #      #    #       \n");
printf("#     #  #######  #  #  #   #         #  #  #  #######     #     ####### \n");
printf("#     #  #     #  #   # #   #         #     #  #     #    #      #       \n");
printf("#     #  #     #  #    ##   #         #     #  #     #   #       #       \n");
printf("#######  #     #  #     #   ######    #     #  #     #  #######  ####### \n\n");
}

void maze(){
        char a[MAZESIZE][MAZESIZE]=
                   {"#############################",
                    "#o        #   ### ## ### ####",
                    "# ### # # # #  ##   ## ### ##",
                    "# # # # #  ### ### # # #    #",
                    "#   # #### # # # ###    # ###",
                    "##### #  ### #  ## ## ###   #",
                    "#   # # #  #  #    ##   ## ##",
                    "# # # ## # # # ## #####  # ##",
                    "# # # # ## #  # #   #    ## #",
                    "# #   ##        ### ###  # ##",
                    "# ###### # ##  ##   ##      #",
                    "#       ## ##             # #",
                    "# ######## # # # ###  #   # >",
                    "#     #  # #     #   ## # # #",
                    "##### #  # # # # ###  # # # #",
                    "#     #  # # #   ##  ## # # #",
                    "# # #        ### ## # # #  ##",
                    "# #   ###  ##       #    #  #",
                    "#############################",
                    };
int i,x,y,p,q;
char c;
 x=1;
 y=1; 
 p=12;
 q=28;  
 for(i=0;i<=18;i++)
    puts(a[i]);
 while(x != p || y != q)
 {
     c = getchar();
     if(c == 's')
     {
         if(a[x+1][y] != '#')
         {
             a[x][y] = ' ';
             x++;
             a[x][y]='o';
         }
     }
    if(c == 'w')
    {
         if(a[x-1][y] != '#')
         {
             a[x][y] = ' ';
             x--;
             a[x][y]='o';
         }
    }
    if(c == 'a')
    {
         if(a[x][y-1] != '#')
         {
             a[x][y] = ' ';
             y--;
             a[x][y]='o';
         }
    }
    if(c == 'd')
    {
         if(a[x][y+1] != '#')
         {
             a[x][y] = ' ';
             y++;
             a[x][y]='o';
         }
    }
         system("");
         for(i=0;i<=18;i++)
            puts(a[i]);
    }
    system("");
    printf("\n")
    printf("Congratulation!!!! YOU WON, you deserve a 100 for you effort:D !!!\n");
}
