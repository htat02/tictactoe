/* Tic Tac Toe game with person vs person or person vs cpu */
#include <stdio.h>
#include <stdbool.h>

int main(){

int gameOption;
int player = 1;
char board[] = { '-','-','-','-','-','-','-','-','-' };
bool game = true;
int maxTurn = 0;

printf("WELCOME TO TIC TAC TOE\n");
while(game){
    createBoard(board);
    insertMarker(board,&player);
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
    printf("Player %d turn\nEnter cords: ", *player);
    scanf("%d",&cords);
    board[cords-1] = *player;
}

/*prompt user for game they wish to play (PVP or PVE) 
void chooseGame(int gameOption){
    printf("Select an Option:\n");
    printf("1 -- person vs. person\n2 -- person vs. random computer\n");
    scanf("%d",&gameOption);
    }
    */

void nextTurn(char *player){
    if(*player == 1){
        *player = 2;
    }
    else {*player = 1;
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
}

bool drawCheck(int maxTurns){
    if(maxTurns<9){
        return false;
    }
    return true;
}
