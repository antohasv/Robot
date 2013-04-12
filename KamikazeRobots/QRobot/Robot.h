#ifndef ROBOT_H
#define ROBOT_H

#include "Unit.h"
#include "Battery.h"

class Robot : public Unit
{
public:
    Battery battery;
public:
    Robot(int limit); // Battery limit
protected:
    void meetRobot();
};

#endif // ROBOT_H
