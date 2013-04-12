#include "Battery.h"

Battery::Battery(int limit)
{
    this ->limit = limit;
    this ->power = limit;
}

int Battery::getPower() {
    return this -> power;
}

void Battery::setPower(int power) {
    if (power >= 0 && power <= limit)
        this -> power = power;
}
