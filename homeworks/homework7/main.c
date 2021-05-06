//Con ayuda de un compañero externo Juan Yamamoto

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "function.h"

#define BACK 0
#define OUT 1

int main(){
    int temppin, temptime, pin, option;
    int flag,bucle = 1 ; 
    int user;
    time_t times = time(0);
    struct tm *timelocal = localtime(&times);
    char out[128];
    char buffer[32];

    printf("Today is %2d/%2d/%d", timelocal->tm_mday,timelocal->tm_mon+1,timelocal->tm_year+1900); 
    printf("\nThere are %d:%d:%2d",timelocal->tm_hour-5,timelocal->tm_min,timelocal->tm_sec); 
    printf("\nHi, are you a user or administrator?\n1 for user, 2 if you are admin\n"); 
    scanf("%d", &option);
    if (option == 1){ 
        option = 0;
        printf("Welcome, enter your pin: \n");
        scanf("%d", &pin);
        if (checkPines(pin) != 1){ 
            printf("that pin does not exist, check the registry of valid pins in system.tx or create that user as administrator\n");
            printf("See you soon!\n");
            exit(1);
        }
        printf("Person #%d  ** Welcome to registration ** \nWhat do you want to do?\n", pin);
        printf("-Press 1 to dial entry-")
        printf("\n-Press 2 to dial out-\n");
        scanf("%d", &option);
        switch (option){
        case 1: 
            flow = fopen("log.txt", "a");
            printf("Your pin entry has been registered:%d today:%s %s\n", pin, out, buffer);
            printf("Entry marked at %d:%d:%2d",timelocal->tm_hour-5,timelocal->tm_min,timelocal->tm_sec); 
            fprintf(flow, "e%d %lu %s %s\n", pin, (unsigned long)time(NULL), out, buffer);
            printf("\nÉxito en el trabajo");
            fflush(flow);
            fclose(flow);
            break;
        case 2: 
            flow = fopen("times.txt", "r+");
            while (flag != BACK){
                fscanf(flow, "%d %d", &temppin, &temptime);
                if (temppin == pin){
                    temptime += workingTime(pin);
                    fseek(flow, -3, SEEK_CUR);
                    fprintf(flow, "%d %d", pin, temptime);
                    fflush(flow);
                    fclose(flow);
                    flag = BACK;
                }
            }
            flow = fopen("log.txt", "a");
            printf("Your pin output has been registered:%d today:%s %s\n", pin, out, buffer);
            printf("Departure marked at %d:%d:%2d",timelocal->tm_hour-5,timelocal->tm_min,timelocal->tm_sec); 
            fprintf(flow, "s%d %lu %s %s %d\n", pin, (unsigned long)time(NULL), out, buffer, workingTime(pin));
            printf("\n Has worked for %d seconds \n see you soon\n", workingTime(pin));
            fflush(flow);
            fclose(flow);
            fprintf(flow, "%d %d\n", pin, workingTime(pin));
            break;
        }
    }

    else if (option == 2){ 
        option = 0;
        printf("Welcome, enter your pin: \n");
        scanf("%d", &pin);
        if (pin != 000){
            printf("YOU ARE NOT AN ADMINISTRATOR\n");
            EOF;
        }
        else{
            while (bucle == OUT){
                option = 0;
                printf("\nHow's it going, how can I help you now?\n");
                printf("Dial 1 if you want to see the attendances of a user\n")
                printf("Dial 2 if you want to add a new worker\n");
                printf("Dial 3 if I want to see a user's hours worked \t Dial 4 if you want to exit\n");
                fflush(stdin);
                scanf("%d", &option);
                switch (option){
                case 1: 
                    printf("Write the user's pin to see their assists (make sure it is valid): \n");
                    fflush(stdin);
                    scanf("%d", &pin);
                    if (checkPines(pin) != OUT){ 
                        printf("That pin does not exist, check the registry of valid pins in system.tx or create that user\n");
                        printf("see you soon!\n");
                        exit(OUT);
                    }
                    asistances(pin);
                    break;
                case 2:
                    registered();
                    break;
                case 3:
                    printf("Write the user's pin to see their assists (make sure it is valid): \n");
                    fflush(stdin);
                    scanf("%d", &pin);
                    if (checkPines(pin) != OUT){ 
                        printf("That pin does not exist, check the registry of valid pins in system.tx or create that user \n");
                        printf("I'm sorry but we have to say goodbye, see you soon!\n");
                        exit(OUT);
                    }
                    printf("The user with the pin: %d,  has worked for %d seconds \n", pin, laborHours(pin));
                    break;
                    case 4:
                        exit(OUT);
                        break;
                }
            }
        }
    }
    else{
        printf("We regret not being able to assist you but you did not write a valid option. Press enter to exit...");
        exit(BACK);
    }
} 
