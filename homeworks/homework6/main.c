//It is not working but I did my best effort

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <ctype.h> 

#include "tree.h"

#define MAX 10
#define START 1

int main(int argc, char const *argv[])
{
    char u[MAX], p[MAX], function[MAX];

    node* n = NULL;
    node* family = NULL;
    
    printf("Place your username and password: \n");
    
    while (START)
        
        scanf("%s %s %s", function, u, p);
        
	while((convert_to_line(user, pass)) != EOF ) {
		if (strstr(ins, "add")) {
			n = 0;
			while (i != '\t') {
				temp[i] = user[i];
				temp[i] = pass[i];
				i++;
			}

			n = insert(temp, temp, tree, 0);
			if (tree == NULL) {
				tree = n;
			}

    if (strcmp(function, "add") == 0 )
      if (strlen(p) > 0 && strlen(u) > 0)  
        n = insert(u,p, family, 0);
	    if (family == NULL) 
	        family = n;   
  }