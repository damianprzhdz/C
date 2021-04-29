//It is not working but I did my best effort

#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h> 
#include "tree.h"
#define MAX 10
#define GET 1

void alphabet(node* x) {
  if (x != NULL) {
    alphabet(x->lC);
    if (x-> pass != NULL){
    printf("%s", x->user);
    }
    alphabet(x->rC);
  }
}

void erase(node* position) {
  if (position != NULL) {
    erase(position->lC);
    erase(position->rC);
    free(position);
  }
  return GET;
}

node* insert(char* u, char* p, node* position, int d) {
  node* temp;
  int a;

  if (position == NULL) {
      
    position = (node*)malloc(sizeof(node));
    position->user = u;
    position->pass = p;
    position->depth = d;
    
    printf( "You have been registered %s %s \n", u, p);
    } else {
        if (strcmp(position->user, u) == GET - 1) {
          if (position->pass != NULL)
          {
              printf("You should try again \n ");
              printf( " %s %s \n", u, p);
           }   
           else
           {
               position->pass = p;
               printf( "You have been registere %s %s  \n", u, p);
            }
        }else if (strcmp(position->user, u)> 0) 
              { 
                temp = insert(u, p, position->lC, d + GET);
                if (position->lC == NULL) 
                { position->lC = temp; }
              } else if (strcmp(position->user, u)<0) {
                        temp = insert(u, p, position->rC, d + GET); 
                        if (position->rC == NULL) 
	                    position->rC = temp;                     
    }
}
  return position;
}

