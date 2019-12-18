#include "Window.h"
#include <iostream>

using namespace std;

Window::Window()
{
  idletime = 0;
}

Window::Window(Window const &window)
{
  idletime = window.idletime;
  occupiedtime = window.occupiedtime;
}

Window::~Window()
{
  //empty
}

void Window::setOccupied(bool what)
{
  occupied = what;
}

bool Window::getOccupied()
{
  return occupied;
}

void Window::setIdleTime(int d)
{
  idletime = d;
}

int Window::getIdleTIme()
{
  return idletime;
}

void Window::setOccupiedTime(int d)
{
  occupiedtime = d;
}

int Window::getOccupiedTime()
{
  return occupiedtime;
}
