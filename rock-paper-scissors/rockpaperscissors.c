// This one was rough mainly due to strcmp(), pointers, and other crap i hardly know

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MOVE_LENGTH 10
// color for some pizzazz
#define CPUCOLOR "\e[38;5;14m"
#define PLRCOLOR "\e[38;5;220m"
#define RESET "\e[38;5;255m"

int main(){
    srand(time(NULL));
    int i = 0;
    char player[MAX_MOVE_LENGTH];
    char *moves[] = {"ROCK","PAPER","SCISSORS"}; // POINTING TO A STRING IN THE ARRAY

    int rnum = rand() % 3; // rand() % MAX_NUMBER (it's like saying randint(1,3))

    printf("ROCK, PAPER, SCISSORS, SHOOT! ");
    fgets(player, sizeof(player), stdin);
    player[strcspn(player, "\n")] = 0;

    // CONVERTS TO UPPERCASE
    // scans through each character in the string and converts it into uppercase. 
    for (int i = 0; player[i]; i++) {
        player[i] = toupper(player[i]);
    }

    while (strcmp(player, moves[0]) != 0 && strcmp(player, moves[1]) != 0 && strcmp(player, moves[2]) != 0){
        printf("INVALID OPTION! TRY AGAIN.\n");
        printf("ROCK, PAPER, SCISSORS, SHOOT! ");
        fgets(player, sizeof(player), stdin);
        player[strcspn(player, "\n")] = 0;
        for (int i = 0; player[i]; i++) {
        player[i] = toupper(player[i]);
        }
    }

    printf(CPUCOLOR "COMPUTER: " RESET "%s\n", moves[rnum]); // PRINT MOVES AT THE INDEX OF THE RANDOM NUMBER
    printf(CPUCOLOR "YOU: " RESET "%s\n", player);

    if (strcmp(player, moves[rnum]) == 0){ // strcmp(string1. string2): COMPARES TWO STRINGS AND RETURNS A 
            printf("TIE!\n");
    }

    else if (strcmp(player, "ROCK") == 0){
        if (strcmp(moves[rnum], "PAPER") == 0){
            printf("YOU LOST!\n");
        }
        else if (strcmp(moves[rnum], "SCISSORS") == 0){
            printf("YOU WON!\n");
        }
    }
    else if (strcmp(player, "PAPER") == 0){
        if (strcmp(moves[rnum], "SCISSORS") == 0){
            printf("YOU LOST!\n");
        }
       else if (strcmp(moves[rnum], "ROCK") == 0){
            printf("YOU WON!\n");
        }
    }
    else if (strcmp(player, "SCISSORS") == 0){
        if (strcmp(moves[rnum], "ROCK") == 0){
            printf("YOU LOST!\n");
        }
        else if (strcmp(moves[rnum], "PAPER") == 0){
            printf("YOU WON!\n");
        }
    }
    return 0;
}