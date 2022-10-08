/* Tic Tac Toe game with person vs person or person vs cpu */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gamefunctions.h"

int main(void){
    int replay;
    int gameOption;
    int cords;
    char player = 'X';
    char board[] = { '-','-','-','-','-','-','-','-','-' };
    bool game = true;
    int maxTurn = 0;

    printf("WELCOME TO TIC TAC TOE\n");
    
    /*prompt user for game they wish to play (PVP or PVE) */
    printf("Select an Option:\n");
    printf("1 -- person vs. person\n2 -- person vs. random computer\n");
    scanf("%d",&gameOption);
    if(gameOption == 1){
        pvp(board, player, maxTurn, replay, game);
    }
    else if(gameOption ==2){
        pve(board, player, maxTurn, replay, game);
    }
}