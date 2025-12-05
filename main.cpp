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
void game(char room[20], char* stuff[5]);

int main(){
  cout << "Welcome to Zuul!" << endl << "There are 15 rooms" << endl << "You need to collect the 5 items scattered around"<< endl << "Once you collect all the items, you need to reach the black room" << endl << endl;
  char room[20] = "red";
  char* stuff[5];
  game(room, stuff);
  return 0;
}
  //start game!
void game(char room[20], char* stuff[]){
  const char *validcmd[] = {"go", "quit", "help", "get", "drop", "stuff"}; 
  bool win = false;
  
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
	  for(int j=0; j < (strlen(request)-i); j++){
	    noun[j] = request[j+i+1];
	  }
	  break; // Galbraith said the break is ok here
	}else if(i == (strlen(request))-1){
	    command[i+1] = '\0';
	    noun[0] = '\0';
	  }
    }
    bool allowcmd = false; //check if the command the user inputed is allowed
    for (int i = 0; i < 6; i++){
      if (strcmp(command, validcmd[i])==0){
	allowcmd = true;
      }
    }
    if (allowcmd == false){
      cout << "That is not a valid command, type 'help' to get commands" <<endl;
      game(room, stuff);
    }

    //now will do the action
    if (strcmp(command, "help")==0){
      cout << "It appears you are offline, check back later." << endl << "Your commands are: ";
      for (int i = 0; i < 6; i++){
	cout << validcmd[i] << "     ";
      }
      cout << endl << endl;
    } else if(strcmp(command, "go")==0){
      cout<< "you went somewwhere" << endl;
    }else if(strcmp(command, "quit")==0){
      win = true;
    }else if(strcmp(command, "get")==0){
      cout << "cool" << endl;
    }else if(strcmp(command, "drop")==0){
      cout << "oops, u dropped smth";
    }else if(strcmp(command, "stuff")==0){
      cout << "Your stuff:" << endl;
      int count = 0;
      while (stuff[count] != "/0"){
	cout << stuff[count] << endl;
	count++;
      }
      cout << endl;
    }else{
      cout << "ERRORR!!!!";
    }
    
  }
}
