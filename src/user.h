/*Name:user.h
  Owner:Kristijonas Bileisis
  Last Date Modified: 11/07/2019
  Description: User header file
*/
#ifndef USER_H
#define USER_H


using namespace std;


class user{

private: 
  int number;
  string name;
public:
  user();
  int getNumber();
  void setNumber(int);
  void setName(string);
  string getName();

};


#endif