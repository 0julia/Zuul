#include <iostream>
#include <cstring>
using namespace std;

/*
  GAME INSTRUCTIONS:
There are 5 items that you need to get and once you reach the black room 
with those items, you win
The items are:
    in the SCARLET room: APPLE
    in the PEACH room: PEACH
    in the JADE room: LEAF
    in the BLACK room: PENGUIN
    in the PINK room: FLAMINGO

*/

int main(){
  bool win = false;
  char room[20] = "red";
  cout << "Welcome to Zuul!" << endl << "There are 15 rooms" << endl << "You need to collect the 5 items scattered around"<< endl << "Once you collect all the items, you need to reach the black room";
  while(win == false){
    char request[20]; // what the user inputs
    char command[20]; // the command (eg go, quit, help, etc)
    char noun[20]; //the object or location the person wants
    cout << "You are in " << room << " room." << endl << "What would you like to do? ";
    cin >> request;
    //    cout << request[4];
    for (int i = 0; i < 20; i++) {
        if (request[i] == ' ') {
	  for(int j=0; j < i; j++){
	    strcpy(command, request);
	    //command[j]=request[j]; // is this a pointer or creating new memory?
	  }
	  for(int j=0; j < (20-i); j++){
	    noun[j] = request[j+i];
	  }
	  
            break; // Exit the loop once the character is found
        }
    }
    cout << command << endl << noun;
    
  }
  return 0;
}
