Name:main.cpp
Owner:Kristijonas Bileisis
Last Date Modified: 11/07/2019
Description: A basic Tic-Tac-Toe game consisting of two players. The players enter their names, play
Tic-Tac-Toe, and then they can continue playing or exit the game if their is a tie or somebody wins
the game. 

How To Play:
  First enter a name for Players 1 and 2.
  Coordinates are entered in the following fashion, "#,#'.
  "#" is an integer of 1,2 or 3.
  The first "#" is the row. The second "#" is the column. For example, "1,1". 
  Insert a "," between the two integers in order for it to be a valid format. 
  Players take turns entering 'x' and 'o' in empty spaces until a player wins
  or there are no more available spaces. You cannot put a 'x' or 'o' in a space that
  already contains an 'x' or 'o'. 
  Incorrect input will prompt the player to put in new coordinates.
  Once the game is finished, the user either puts in 'y' or 'n' to continue playing or
  to exit the game. 
  

How to Win:
  In order to win, you must get three 'x' or 'o' in a row,column or diagnolly. 

  A win by row:
  x|x|x
  -----
  o|o|x
  -----
  o|x|o

  A win by column:
  o|x|x     
  -----
  o|x|x
  -----
  o|x|o 
     

  A win by dianolly:
  o|x|x
  -----
  o|o|x
  -----
  o|x|o


How to Tie:
  If all spaces have been filled with an 'x' or 'o' and no player has won by 
  getting three 'o' or 'x' in a row, column or diagnolly, then the players tie. 







