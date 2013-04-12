#ifndef DOOR_H
#define DOOR_H

#include "Unit.h"


class Door : public Unit {
  // Attributes
  // Operations
public:
  Door();
  Door(int x, int y);
  void meetRobot();
};

#endif // DOOR_H
