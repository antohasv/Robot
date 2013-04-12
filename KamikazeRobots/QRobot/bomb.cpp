#include "Bomb.h"

void Bomb::meetRobot() {
    this ->setIsALive(false);
}

Bomb::Bomb(int x, int y) {
    setX(x);
    setY(y);
}
