#include <stdio.h>
#include "homework4.h"

int sp=0;
double val[MAXVALUE];

void push(double f)
{
  if(sp < MAXVALUE)
     val[sp++]=f;
   else
   printf("error:stack full, cant push %g\n",f);
}

double pop(void)
{
    if(sp>0)
      return val[--sp];
    else
    {
      printf("error: stack empty\n");
      return 0.0;
    }
}