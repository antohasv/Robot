#include "Star.h"

void Star::meetRobot() {
    this ->setIsALive(false);
}

Star::Star(int x, int y) {
    setX(x);
    setY(y);
    this ->setIsALive(true);
}
