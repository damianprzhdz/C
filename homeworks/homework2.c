// With help of Angells, AntonioCG2002 and Youtube videos

#include <stdio.h>
#include <math.h>
#define K  10   //The prime numbers you want to put
#define MAX 256 //How many bits we will put 

int main (int argc, char const *argv[]){   //This is to obtain the prime numbers
	int a, i,count = 0,state = 0;  // if we want to put more prime numbers we will put long
    unsigned long bin = MAX;  
	for(i = 2 ; count < K ;i++){
        state = 0;
		for(a = 2 ; a <= i ;a++){  
		if(i % a == 0)  // this will represent and detect the prime numbers by the modulus
            state++;
	}
        if(state == 1){ //if state is one that means that is a prime number
		printf("\t%02d = ",i); 
        count++; 
		state = 0 ;
      for(bin = MAX; bin > 0; bin >>= 1){
        if (bin & i) {
            printf("1");
		} else {
            printf("0"); }
      }
      printf("\n");
    }
  }
}
