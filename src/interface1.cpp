/*Name:interface1.cpp
  Owner:Kristijonas Bileisis
  Last Date Modified: 11/07/2019
  Description: Interface class for the logic and display of the game and board.
*/
#include <iostream>
#include "interface1.h"
#include "user.h"
#include <stdio.h>
#include <limits.h>
#include <string>
#include <sstream>


using namespace::std;


//interface constructor
interface1::interface1(){
  char inter[5][5];
}


/*creates the board for the tic tac toe game. It is also used for resetting the board
  once a player wins*/
void interface1::genInterface(){
  for (int i=0;i<5; i++){
    for (int j=0; j<5; j++){
      if ((i==0||i==2||i==4)&&(j==1||j==3)){
        inter[i][j]='|';
      }else if (i==1||i==3){
        inter[i][j]='-';
      }else inter[i][j]=' ';
    }
  }
}


//populates the board with 'x' and 'o' depending on which player it is
void interface1::updateInterface1(int row, int col, int id){
  if (id==1){
    inter[row][col]='x';
  }else inter[row][col]='o';
}


// prints the board onto the screen
void interface1::displayInterface1(){
  for (int i=0;i<5;i++){
    for (int j=0; j<5; j++){
      cout<<inter[i][j];
    }cout<<endl;
  }
}


//function determining if a player has won the game
bool interface1::ifWon(int id){
  if (id==1){
    if (inter[0][0]=='x'&&inter[2][2]=='x'&&inter[4][4]=='x'){ //diagnol
      return true;
    }else if (inter[0][4]=='x'&&inter[2][2]=='x'&&inter[4][0]=='x'){ //diagnol
      return true;
    }else if (inter[0][0]=='x'&&inter[0][2]=='x'&&inter[0][4]=='x'){ //1st row
      return true;
    }else if (inter[2][0]=='x'&&inter[2][2]=='x'&&inter[2][4]=='x'){ //2nd row
      return true;
    }else if (inter[4][0]=='x'&&inter[4][2]=='x'&&inter[4][4]=='x'){ //3rd row
      return true;
    }else if (inter[0][0]=='x'&&inter[2][0]=='x'&&inter[4][0]=='x'){ //1st col
      return true;
    }else if (inter[0][2]=='x'&&inter[2][2]=='x'&&inter[4][2]=='x'){ //2nd col
      return true;
    }else if (inter[0][4]=='x'&&inter[2][4]=='x'&&inter[4][4]=='x'){ //3rd col
      return true;
    }else return false;

  }
  if (id==2){
    if (inter[0][0]=='o'&&inter[2][2]=='o'&&inter[4][4]=='o'){ //diagnol
      return true;
    }else if (inter[0][4]=='o'&&inter[2][2]=='o'&&inter[4][0]=='o'){ //diagnol
      return true;
    }else if (inter[0][0]=='o'&&inter[0][2]=='o'&&inter[0][4]=='o'){ //1st row
      return true;
    }else if (inter[2][0]=='o'&&inter[2][2]=='o'&&inter[2][4]=='o'){ //2nd row
      return true;
    }else if (inter[4][0]=='o'&&inter[4][2]=='o'&&inter[4][4]=='o'){ //3rd row
      return true;
    }else if (inter[0][0]=='o'&&inter[2][0]=='o'&&inter[4][0]=='o'){ //1st col
      return true;
    }else if (inter[0][2]=='o'&&inter[2][2]=='o'&&inter[4][2]=='o'){ //2nd col
      return true;
    }else if (inter[0][4]=='o'&&inter[2][4]=='o'&&inter[4][4]=='o'){ //3rd col
      return true;
    }else return false;
  }
}

//check if the game ended in a tie
bool interface1::ifTied(){
  for (int i=0;i<5;i++){
    for (int j=0;j<5;j++){
      if (inter[i][j]==' '){
        return false;
      }
    }
  }
  return true;
}


//function for getting player names
void interface1::setUp(user & player1, user & player2){
  cout<<"WELCOME TO THE BEST TIC TAC TOE GAME EVER!\nENTER COORDINATES IN THE FORMAT '#,#'."<<endl;
  string s;
  cout<<"ENTER NAME FOR PLAYER 1:";
  getline(cin,s);
  player1.setName(s);
  player1.setNumber(1);
  cout<<"ENTER NAME FOR PLAYER 2:";
  getline(cin,s);
  player2.setName(s);
  player2.setNumber(2); 
}


//function asking for player moves and the logic for how the game is played
void interface1::playGame(int & id, int row, int col, user & player1, user & player2, bool & over,bool & tied){
  bool valid=false;

  //if input is in away incorect, it will loop back and ask the player to put in new input 
  while (valid==false){
    valid=true;
    string s;

    //ask player to input coordinates
    if (id==1){
      cout<<player1.getName()<<" ENTER COORDINATES:";
    }
    if (id==2){
      cout<<player2.getName()<<" ENTER COORDINATES:";  
    }
    
    //check to make sure the input are integers
    getline(cin,s);
    row= s[0]-'0';
    col= s[2]-'0';
    if (s[1]!=','){
      valid=false;
    }
    
    //change row and col input to valid spots in the array
    if (valid==true){
      if (row==1){
        row=0;
      }else if (row==3){
        row=4;
      }else if (row==2){
        row=2;
      }else {
        valid=false;
      }
      if (col==1){
        col=0;
      }else if (col==3){
        col=4;
      }else if (col==2){
        col=2;
      }else {
        valid=false; 
      }
    }

    //if input is incorrect, tell user that the input is wrong
    if (valid==false){
      cout<<"Invalid coordinates: Try again"<<endl;
      displayInterface1();
    }

    //check to make sure the coordinates enters aren't already on the board
    if ((inter[row][col]=='x'||inter[row][col]=='o')&&(valid==true)){
      cout<<"THAT SPOT IS ALREADY TAKEN. TRY AGAIN."<<endl;
      valid=false;
      displayInterface1();
    }
     
  }

  updateInterface1(row, col, id); 

  //if coordinates are valid, check if the game has been won or tied
  if (ifWon(id)==true){
    displayInterface1(); 
    if (id==1){
      cout<<player1.getName()<<". You Won!"<<endl;
    }
    if (id==2){
      cout<<player2.getName()<<". You Won!"<<endl;
    }
    cout<<"GAME OVER! ";
    over=true;
  }
  if (ifTied()==true&&over!=true){
    displayInterface1();
    cout<<"TIE GAME!\n";
    over=true;
  }   

  //change players at the end of the turn
  if (id==1){
    id=2;
  }else id=1;
}

//prompt user if they want to play again
void interface1::replay(bool & won,bool & tied,bool & playagain, char & yon){
  bool val=false; 

  //only prompt user if they like to play again if the game has been won or tied
  if (won==true||tied==true){

    //keep prompting the user until they type in either a 'y' or 'n'
    while (val==false){
    cout<<"WOULD YOU LIKE TO PLAY AGAIN? 'y' for yes, 'n' for no: ";
    cin>>yon;
      if (yon=='y'){
        playagain=true;
        val=true;
      }else if (yon=='n'){
        playagain=false;
        val=true;
      }else{
        cout<<"Invalid character: Try Again"<<endl;
        val=false;
      } 
    }

  //if players want to play again, reset the board and win&tied flags
  won=false;
  tied=false;
  genInterface();
  }
}


