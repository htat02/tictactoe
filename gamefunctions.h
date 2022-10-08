#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

/* Create Board */ 
void createBoard(char board[]){
    int i;
   for (i = 0; i < 9; i++) {
      printf("%c ", board[i]);
      if (((i + 1) % 3) == 0) {
         printf("\n");
      }
   }
}

void insertMarker(char board[], char *player){
    int cords;
    do{
    printf("Player %c turn\nEnter cords(1-9): ", *player);
    scanf_s("%d",&cords);
    if (cords <1 || cords >9){
        printf("INVALID INPUT. RETRY!\n");}

    /*if(board[*player] == 'X' || board[*player] == 'O'){
        printf("INVALID INPUT. RETRY!\n");*/

    }while(cords <1 || cords >9);
    
    board[cords-1] = *player;
    }

void nextTurn(char *player){
    if(*player == 'X'){
        *player = 'O';
    }
    else {*player = 'X';
    }
}

/* Check winner*/
bool winCheck(char board[]){
    bool win=false;

    /* row win */
    if (board[0] != '-'){
        if (board[0]== board[1]){
            if (board[0]==board[2]){
                win = true;
            }
        }
    }
    if (board[3] != '-'){
        if (board[3]== board[4]){
            if (board[3]==board[5]){
                win = true;
            }
        }
    }
    if (board[6] != '-'){
        if (board[6]== board[7]){
            if (board[6]==board[8]){
                win = true;
            }
        }
    }

    /*column win */\
    if (board[0] != '-'){
        if (board[0]== board[3]){
            if (board[0]==board[6]){
                win = true;
            }
        }
    }
    if (board[1] != '-'){
        if (board[1]== board[4]){
            if (board[1]==board[7]){
                win = true;
            }
        }
    }
    if (board[2] != '-'){
        if (board[2]== board[5]){
            if (board[2]==board[8]){
                win = true;
            }
        }
    }

    /* diagonal win */
    if (board[0] != '-'){
        if (board[0]== board[4]){
            if (board[0]==board[8]){
                win = true;
            }
        }
    }
    if (board[2] != '-'){
        if (board[2]== board[4]){
            if (board[2]==board[6]){
                win = true;
            }
        }
    }
    return win;
}

/* check draw */
bool drawCheck(int maxTurns){
    if(maxTurns<9){
        return false;
    }
    return true;
}

void cpu(char board[], char *player){
    srand(time(0));
    int r = (rand()%9)+1;
    board[r-1] = &player;
}

void pvp(char board[], char *player, int maxTurn, int replay, bool game){
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

void pve(char board[], char *player, int maxTurn, int replay, bool game){
while(game){
            createBoard(board);
            insertMarker(board, &player);
            maxTurn++;
            cpu(board, player);
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