#ifndef STAR_H
#define STAR_H

#include "Unit.h"

class Star : public Unit {
//private:
  //  Field field;
public:
    Star(int x, int y);
    void meetRobot();
};

#endif // STAR_H
