#include "Unit.h"

Unit::Unit()
{
}

void Unit::setX(int x) {
    this -> x = x;
}

void Unit::setY(int y) {
    this -> y = y;
}


int Unit::getX() {
    return this -> x;
}

int Unit::getY() {
    return this -> y;
}

void Unit::setIsALive(bool isALive) {
    this -> isLive = isALive;
}

bool Unit::getIsALive() {
    return this -> isLive;
}
