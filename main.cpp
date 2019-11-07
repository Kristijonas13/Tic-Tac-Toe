/*Name:main.cpp
  Owner:Kristijonas Bileisis
  Last Date Modified: 11/07/2019
  Description: A basic Tic-Tac-Toe game consisting of two players. The players enter their names, play
  Tic-Tac-Toe, and then they can continue playing or exit the game if their is a tie or somebody wins
  the game. 
*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include "user.h"
#include "interface1.h"

using namespace std;


int main() {
  //create two players and create the game
  user player1;
  user player2;
  interface1 game;

  //variables to determine if the game is tied or won, or if they want to play again
  bool won=false;
  bool tied=false;
  bool playagain=true;
  char yon;
  int id=1;
  
  //start the tic-tac-toe game and prompt players for names 
  game.genInterface();
  game.setUp(player1, player2);

  //run the game until the players decide they don't want to play anymore
  while (playagain==true){
    int row=0;
    int col=0;
    game.displayInterface1();
    game.playGame(id,row,col,player1,player2,won,tied);
    game.replay(won,tied,playagain,yon);
  }
  cout<<"THANKS FOR PLAYING!"<<endl;
  return(0);
}