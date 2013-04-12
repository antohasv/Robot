#include "Power.h"

void Power::meetRobot() {
    this ->setIsALive(false);
}

Power::Power(int x, int y) {
    setX(x);
    setY(y);
}
