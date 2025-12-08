#include <iostream>
#include "room.h"

using namespace std;

room::room(const char* desc) {
  strcpy(description, desc);
  strcpy(item, "nothing");
  
  // initialize exits
  for (int i = 0; i < 4; i++) {
    exitRooms[i] = nullptr;
    exitNames[i][0] = '\0';
  }
}

int room::findExitIndex(const char* dir) {
  for (int i = 0; i < 4; i++) {
    if (strcmp(exitNames[i], dir) == 0)
      return i;
  }
  return -1;
}

void room::setExit(const char* dir, room* neighbor) {
  int i = findExitIndex(dir);
  
  // If direction not found, find empty slot
  if (i == -1) {
    for (int j = 0; j < 4; j++) {
      if (exitNames[j][0] == '\0') {
	i = j;
	strcpy(exitNames[j], dir);
	break;
      }
    }
  }

  // Assign the room
  if (i != -1)
    exitRooms[i] = neighbor;
}

room* room::getExit(const char* dir) {
  int i = findExitIndex(dir);
  if (i != -1)
    return exitRooms[i];
  return nullptr;
}

void room::setItem(const char* it) {
  strcpy(item, it);
}

const char* room::getItem() {
  return item;
}

const char* room::getDescription() {
  return description;
}
void room::printExits() {
  for (int i = 0; i < 4; i++) {
    if (exitNames[i][0] != '\0')
      cout << exitNames[i] << " ";
  }
}
