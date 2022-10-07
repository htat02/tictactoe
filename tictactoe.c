/* Tic Tac Toe game with person vs person or person vs cpu */
#include <stdio.h>

int main(){
int gameOption;
char turn = 'X';
char board[] = { '-','-','-','-','-','-','-','-','-' }; 
printf("WELCOME TO TIC TAC TOE\n");
createBoard(board); 

}
/*Create Board */ 
void createBoard(char board[]){
    int i;
   for (i = 0; i < 9; i++) {
      printf("%c ", board[i]);
      if (((i + 1) % 3) == 0) {
         printf("\n");
      }
   }
}
/*prompt user for game they wish to play (PVP or PVE) */
void gameOption(int gameOption){
    printf("Select an Option:\n");
    printf("1 -- person vs. person\n2 -- person vs. random computer\n");
    scanf("%d",&gameOption);
    if(gameOption==1)

}

void insertMarker(char board[], char *turn){
    int cords;
    printf("Player %c turn\nEnter cords: ", *turn);
    scanf("%d",&cords);
    board[cords-1] = *turn;
}

/*Present option for player 1 */

/*Present option for player 2 if available */ 

/*CPU action */