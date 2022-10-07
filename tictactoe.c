/* Tic Tac Toe game with person vs person or person vs cpu */
#include <stdio.h>

int main(){
    printf("WELCOME TO TIC TAC TOE\n");

/*Create Board */ 
char board[] = { '-','-','-','-','-','-','-','-','-' };                              
   int i;
   for (i = 0; i < 9; i++) {
      printf("%c ", board[i]);
      if (((i + 1) % 3) == 0) {
         printf("\n");
      }
   }
}


/*prompt user for game they wish to play (PVP or PVE) */

/*Present option for player 1 */

/*Present option for player 2 if available */ 

/*CPU action */