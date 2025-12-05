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
void game();

int main(){
  cout << "Welcome to Zuul!" << endl << "There are 15 rooms" << endl << "You need to collect the 5 items scattered around"<< endl << "Once you collect all the items, you need to reach the black room" << endl << endl;
  game();
  return 0;
}
  //start game!
void game(){
  const char *validcmd[] = {"go", "quit", "help", "get", "drop", "stuff"}; 
  bool win = false;
  char room[20] = "red";
  
  while(win == false){
    char request[20]; // what the user inputs
    char command[10]; // the command (eg go, quit, help, etc)
    char noun[10]; //the object or location the person wants
    cout << "You are in " << room << " room." << endl << "What would you like to do? ";
    cin.getline(request, 10);
    cin.clear();
    // divides the command and the noun from the request
    for (int i = 0; i < strlen(request); i++) {
      command[i]=request[i];
        if (request[i] == ' ') {
	  command[i] = '\0';
	  cout << "checkpoint 3"<<endl;
	  for(int j=0; j < (strlen(request)); j++){
	    noun[j] = request[j+i];
	  }
	  break;
	}else if(i == (strlen(request))-1){
	    command[i+1] = '\0';
	    noun[0] = '\0';
	  }
    }
    cout << endl << "Checkup ";
    cout << command << endl << "Noun: " << noun;
    cout << endl << endl;
    bool allowcmd = false; //check if the command the user inputed is allowed
    for (int i = 0; i < 6; i++){
      if (strcmp(command, validcmd[i])==0){
	allowcmd = true;
      }
    }
    if (allowcmd == false){
      cout << "That is not a valid command, type 'help' to get commands" <<endl;
      game();
    }
  }
}
