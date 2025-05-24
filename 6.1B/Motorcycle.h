#pragma once
#include "Vehicle.h"
#include <iostream>

class Motorcycle : public Vehicle {
public:
    Motorcycle(int red, int green, int blue, const char* num,
        int x1, int y1, int x2, int y2);
    std::ostream& Print(std::ostream& os) const override;
};