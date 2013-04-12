#ifndef UNIT_H
#define UNIT_H

#include "Image.h"

/// class Unit -
class Unit {
  // Attributes
public:
    Image img;
private:
  int x;
  int y;
  bool isLive;
  // Operations
public:
  Unit();
  void setData(int x, int y, QString path);
  void setX (int x);
  void setY (int y);
  int getX ();
  int getY ();
  void setIsALive (bool isALive);
  bool getIsALive ();
  virtual void meetRobot () = 0;
};


#endif // UNIT_H
