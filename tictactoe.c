/* Tic Tac Toe game with person vs person or person vs cpu */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gamefunctions.h"

int main(void){
    int replay;
    int gameOption;
    char player = 'X';
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
            printf("Player %c wins!\n", player);
            do{
            printf("Do you want to replay?\n1 -- YES\n2 -- NO\n");
            scanf("%d", &replay);
            if(replay <1 || replay >2){
                printf("INVALID INPUT. RETRY!\n");
            }
            if(replay == 2){
                exit(0);
            }
            else{
                for(int i=0;i<9;i++)
                {
                    board[i] = '-';
                }
                maxTurn=0;
            }
        }while(replay <1 || replay >2);
        }

        if(drawCheck(maxTurn)){
            createBoard(board);
            do{
            printf("The game is a draw!\n");
            printf("Do you want to replay?\n1 -- YES\n2 -- NO\n");
            scanf("%d", &replay);
            if(replay <1 || replay >2){
                printf("INVALID INPUT. RETRY!\n");
            }
            if(replay == 2){
                exit(0);
            }
            else if(replay == 1){
                for(int i=0;i<9;i++)
                {
                    board[i] = '-';
                }
                maxTurn=0;
            }
            }while(replay <1 || replay >2);
        }
        nextTurn(&player);
    }
}