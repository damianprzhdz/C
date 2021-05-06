#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "function.h"

int asistances(int pin){
    int c, asistances = 0;
    FILE *expediente;
    expediente = fopen("log.txt", "r");
    while ((c = fgetc(expediente)) != EOF){
        if (c == 's'){
            c = fgetc(expediente) - '0';
            if (c == pin){
                asistances++;
            }
        }
    }
    fflush(expediente);
    fclose(expediente);
    printf("\nThe user %d has : %d asistances\n", pin, asistances);
}

int workingTime(int pin){
    char times1[20], times2[20];
    int time1, time2, tiempo;
    int c, asistances = 0;
    FILE *expediente;
    expediente = fopen("log.txt", "r");
    while ((c = fgetc(expediente)) != EOF){
        if (c == 'e'){
            c = fgetc(expediente) - '0';
            if (c == pin){
                c = fgetc(expediente) - '0';
                fgets(times, 11, expediente);
                time1 = atoi(times);
            }
        }
    }
    times = (unsigned long int)time(NULL) - time1;
    fflush(expediente);
    fclose(expediente);
    return times;
}
int laborHours(int pin){
    int hours, c, pinc;
    FILE *expediente;
    expediente = fopen("times.txt", "r");
    while (1) {
        fscanf(expediente, "%d %d", &pinc, &hours);
        if (pinc == pin){
            return hours;
            break;
        }
    }
}

int registered(void){
    int np = 1;
    int pin; 
    int flag = 0;
    char hours0[30];
    char hours[30]; 
    char days[40];
    FILE *experdiente;
    expediente = fopen("system.txt", "a");
    if (expediente == NULL){
        printf("Caution: The file could not be created system.txt\n");
    } else {
        while (1){
            if (pines(np))
                np++;
            else{
                continue;
            }
        }

        expediente = fopen("system.txt", "a");
        printf("The new automatically generated pin is : %d\n", np);
        printf("Enter the days you will work, without spaces\n");
        fflush(stdin);
        scanf("%s", days);
        printf("Enter the worker's entry time\n");
        fflush(stdin);
        scanf("%s", hours);
        printf("Enter the worker's departure time\n");
        fflush(stdin);
        scanf("%s", hours0);
        fprintf(expediente, "c%d e%s s%s d%s\n", np, hours0, hours, days);
        printf("Successfully added, thank you very much");
        fflush(expediente);
        fclose(expediente);
        expediente = fopen("times.txt", "a");
        fprintf(expediente, "%d 0 \n", np);
        fflush(expediente);
        fclose(expediente);
        printf("\n");
    }
}

int pines(int pin){
    int pines[9], j = 0;
    int c;
    FILE *expediente;
    expediente = fopen("system.txt", "r");
    if (expediente == NULL){
        printf("Caution: The file could not be created system.txt\n");
    }
    else{
        while ((c = fgetc(expediente)) != EOF){
            if (c == 'c'){
                c = fgetc(expediente);
                pines[j] = c - '0';
                if (pin == pines[j]){
                    fflush(expediente);
                    fclose(expediente);
                    return 1;
                }
                j = +1;
            }
        }
    }
    fflush(expediente);
    fclose(expediente);
    
    return BACK;
}

