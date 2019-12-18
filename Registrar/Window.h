#ifndef WINDOW_
#define WINDOW_

#include <iostream>

using namespace std;

class Window
{
public:
  Window();
  Window(const Window&);
  ~Window();
  void setOccupied(bool what);
  bool getOccupied();
  void setIdleTime(int d);
  int getIdleTIme();
  void setOccupiedTime(int d);
  int getOccupiedTime();
private:
  int idletime;
  int occupiedtime;
  bool occupied;
};
#endif
