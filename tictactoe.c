/* Tic Tac Toe game with person vs person or person vs cpu */
#include <stdio.h>
#include <stdbool.h>
#include "gamefunctions.h"

int main(){

    int gameOption;
    int player = 1;
    char board[] = { '-','-','-','-','-','-','-','-','-' };
    bool game = true;
    int maxTurn = 0;

    printf("WELCOME TO TIC TAC TOE\n");
    while(game){
        createBoard(board);
        insertMarker(board, &player);
        maxTurn++;
        if(winCheck(board)){
            createBoard(board);
            printf("Player %d wins!", player);
            exit(0);
        }
        if(drawCheck(maxTurn)){
            createBoard(board);
            printf("The game is a draw!");
            exit(0);
        }
        nextTurn(&player);
    }
}