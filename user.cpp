/*Name:user.cpp
  Owner:Kristijonas Bileisis
  Last Date Modified: 11/07/2019
  Description: User class for creating the players for the tic tac toe game. 
*/
#include <string>
#include "user.h"
#include <iostream>

using namespace std;


//default user constructor
user::user(){
  number=0;
  name= "Sally";
}


//get the id of the player
int user::getNumber()
{
  return number;
}


//set the id of the player
void user::setNumber(int x){
  number=x;
}


//set the name of the player
void user::setName(string s){
  name=s;
}


//get the name of the player
string user::getName(){
  return name;
}


