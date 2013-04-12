#ifndef BOMB_H
#define BOMB_H

#include "Unit.h"

class Bomb : public Unit
{
public:
    Bomb(int x, int y);
    void meetRobot();
};

#endif // BOMB_H
