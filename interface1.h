/*Name:interface1.h
  Owner:Kristijonas Bileisis
  Last Date Modified: 11/07/2019
  Description: Interface header file
*/

#ifndef INTERFACE1_H
#define INTERFACE1_H
#include "user.h"

using namespace std;

class interface1{
  private:
    char inter[5][5];
  public:
    interface1();
    void genInterface();
    void updateInterface1(int,int,int);
    void displayInterface1();
    bool ifWon(int);
    void setUp(user &, user &);
    void playGame(int &,int,int,user &,user &,bool &,bool &);
    void resetInterface1();
    bool ifTied();
    void replay(bool &,bool &,bool &, char &);
    

};
#endif