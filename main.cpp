#include <iostream>
#include <cstring>
#include "room.h"
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
void game(room* currentRoom, char stuff[5][20]);

//defining all the rooms, their stuff, and exits
void createRooms(room*& currentRoom) {
    room* red = new room("in the red room");
    room* orange = new room("in the orange room");
    room* yellow = new room("in the yellow room");
    room* green = new room("in the green room");
    room* blue = new room("in the blue room");
    room* purple = new room("in the purple room");
    room* pink = new room("in the pink room");
    room* black = new room("in the black room");
    room* leaf= new room("in the leaf room");
    room* teal= new room("in the teal room");
    room* scarlet= new room("in the scarlet room");
    room* peach = new room("in the peach room");
    room* jade = new room("in the jade room");
    room* magenta= new room("in the magenta room");
    room* lavender = new room("in the lavender room");

    red->setExit("west", orange);

    orange->setExit("south", peach);
    orange->setExit("west", yellow);
    orange->setExit("east", red);
    orange->setExit("north", scarlet);

    yellow->setExit("east", orange);
    yellow->setExit("west", green);

    scarlet->setExit("south", orange);

    peach->setExit("north", orange);

    green->setExit("north", teal);
    green->setExit("east", yellow);
    green->setExit("south", leaf);

    teal->setExit("south", green);
    teal->setExit("west", blue);

    blue->setExit("east", teal);
    blue->setExit("west", lavender);

    lavender->setExit("west", pink);
    lavender->setExit("east", blue);
    lavender->setExit("south", magenta);

    magenta->setExit("south", purple);
    magenta->setExit("north", lavender);

    purple->setExit("north", magenta);
    purple->setExit("east", black);

    black->setExit("east", leaf);
    black->setExit("west", purple);

    leaf->setExit("south", jade);
    leaf->setExit("west", black);
    leaf->setExit("north", green);

    jade->setExit("north", leaf);
    pink->setExit("east", lavender);

    // items
    scarlet->setItem("apple");
    peach->setItem("peach");
    jade->setItem("leaf");
    black->setItem("penguin");
    pink->setItem("flamingo");

    currentRoom = red;
}

int main(){
  room* currentRoom;
  createRooms(currentRoom);
  cout << "Welcome to Zuul!" << endl << "There are 15 rooms" << endl << "You need to collect the 5 items scattered around"<< endl << "Once you collect all the items, you need to reach the black room" << endl << endl;
  char stuff[5][20];
  for(int i=0; i<5; i++){
    strcpy(stuff[i], " ");
  }
  game(currentRoom, stuff);
  cout << endl << "bye.";

  //delete all rooms
  delete red;
  delete orange;
  delete yellow;
  delete green;
  delete blue;
  delete purple;
  delete pink;
  delete black;
  delete leaf;
  delete teal;
  delete scarlet;
  delete peach;
  delete jade;
  delete magenta;
  delete lavendar;
  return 0;
}


//start game!
void game(room* currentRoom, char stuff[5][20]){
  const char *validcmd[] = {"go", "quit", "help", "get", "drop", "stuff"}; 
  bool win = false;
  
  while(win == false){
    char request[200]; // what the user inputs
    char command[100]; // the command (eg go, quit, help, etc)
    char noun[100]; //the object or location the person wants
    cout << "You are " << currentRoom->getDescription() << endl << "Exits are: ";
    currentRoom->printExits();
    cout <<endl << "Item in the room: " << currentRoom->getItem() <<endl<< endl << "What would you like to do? ";
    cin.getline(request, 100);
    cin.clear();
    // divides the command and the noun from the request
    for (int i = 0; i < strlen(request); i++) {
      command[i]=request[i];
        if (request[i] == ' ') {
	  command[i] = '\0';
	  int counter = 0;
	  for(int j=1; j < (strlen(request)-i); j++){
	    noun[j-1] = request[j+i];
	    counter++;
	  }
	  noun[counter]='\0';
	  break; // Galbraith said the break is ok here
	}else if(i == (strlen(request))-1 && strlen(noun) > 0){
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
      game(currentRoom, stuff);
    }

    //now will do the action
    if (strcmp(command, "help")==0){
      cout << "It appears you are offline, check back later." << endl << "Your commands are: ";
      for (int i = 0; i < 6; i++){
	cout << validcmd[i] << "     ";
      }
      cout << endl << endl;
    } else if(strcmp(command, "go")==0){
      room* next = currentRoom->getExit(noun);
      if (next != nullptr) {
        currentRoom = next;//changwe room
      } else {
        cout << "u just walked into a wall." << endl;
      }
    }else if(strcmp(command, "quit")==0){
      win = true;
    }else if(strcmp(command, "get")==0){
      //if theres smth in the room...
      int location;
      for(int i=0; i<5;i++){
	if (strcmp(stuff[i]," ") == 0){
	  location = i;
	  break;
	}
      }
      if (strcmp(currentRoom->getItem(), "nothing") != 0) {
	strcpy(stuff[location], currentRoom->getItem()); //put in invintroy
        // Remove from room
        currentRoom->setItem("nothing");
	cout << endl;
      } else {
        cout << "thers nothing here..." << endl;
    }
    }else if(strcmp(command, "drop")==0){
      int location=10;
      for(int i=0; i<5;i++){
	if (strcmp(stuff[i], noun) == 0){
	  location = i;
	  break;
	}
      }
      cout << "Location: " << location << endl << "Thing: " << stuff[location] << endl;
      //if thers smth in the inventroy at that location
      if (stuff[location][0] != '\0' && location < 6) {
	currentRoom->setItem(stuff[location]); // put item in room
	stuff[location][0] = '\0';             // remove from inventory	
	cout << "u dropped it" << endl;
      } else {
	cout << "u dont hav that thing" << endl;
	}
    }else if(strcmp(command, "stuff")==0){
      cout << "Your stuff:" << endl;
      for (int i = 0; i < 5; i++) {
        cout << stuff[i]<< endl;
      }
      cout << endl;
    }else{
      cout << "ERRORR!!!!";
    }
    bool done = true;
    for (int i = 0; i<5; i++){
      if(strcmp(stuff[i], " ")==0){
	done = false;
      }
    }
    if (strcmp(currentRoom->getDescription(), "in the black room") == 0 && done == true){
      cout << "goodjob, u won.";
      win = true;
    }
  }
}
