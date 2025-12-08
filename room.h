#include <iostream>
#include <cstring>
using namespace std;

class room{
public:
  room(const char* desc);
  void setExit(const char* dir, room* neighbor);
  room* getExit(const char* dir);
  
  void setItem(const char* item);
  const char* getItem();
  void printExits();
  const char* getDescription();
  
private:
  char description[50];
  char item[20];
  
  // directions: north, south, east, west
  char exitNames[4][10];
  room* exitRooms[4];
  
  int findExitIndex(const char* dir);
};
