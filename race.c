/******************************************************************************

Nathan Zimmerman
4-26-2021
CSC 345
Lab 4
Goal:
• To design and implement functions to process pointers.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


int randInt(){
    int num;
    num = (rand() % 10) + 1;
    return num;
}

int hareMove(int *harePointer, int number){
    if (number == 1 || number == 2) {
        *harePointer = *harePointer;
    } else if (number == 3 || number == 4) {
        *harePointer += 9;
    } else if (number == 5) {
        *harePointer -= 12;
    } else if (number == 6 || number == 7 || number == 8) {
        *harePointer += 1;
    } else {
        *harePointer -= 2;
    }
    if (*harePointer < 1) { *harePointer = 1; }

    return *harePointer;
}

int turtleMove(int *turtlePointer, int number){
    if (number >= 1 && number <= 5) {
        *turtlePointer += 3;
    } else if (number == 6 || number == 7) {
        *turtlePointer -= 6;
    } else {
        *turtlePointer += 1;
    }
    if (*turtlePointer < 1) { *turtlePointer = 1; }

    return *turtlePointer;
}

int main()
{
    srand(time(NULL));

    char hare = 'H';
    char turtle = 'T';
    int harePosition = 1;
    int turtlePosition = 1;
    int *harePointer = &harePosition;
    int *turtlePointer = &turtlePosition;


    puts("ON YOUR MARK, GET SET");
    puts("BANG               !!!!");
    printf("AND THEY'RE OFF    !!!!");
    
    while ( harePosition < 70 && turtlePosition < 70) {
        sleep(1);
        harePosition = hareMove(&harePosition, randInt());
        turtlePosition = turtleMove(&turtlePosition, randInt());

        printf("\n");
        if (harePosition >= 70 && harePosition != turtlePosition) { 
            printf("Hare wins. Yuch."); 
            break;
        }
        if (turtlePosition >= 70 && harePosition != turtlePosition) { 
            printf("TORTOISE WINS!!! YAY!!!"); 
            break;
        }
        if (harePosition >= 70 && turtlePosition >= 70 && harePosition != turtlePosition) { 
            printf("IT IS A TIE!!!"); 
            break;
        }

        if (harePosition == turtlePosition){
            for(int i = 0; i < harePosition; i++){
                printf(" ");
            }
            printf("OUCH!!!");
        } else {
            for(int i = 0; i < 70; i++){
                if(i == harePosition){
                    printf("H");
                } else if (i == turtlePosition){
                    printf("T");
                } else {
                    printf(" ");
                }
            }        
        }
    }

    return 0;
}
