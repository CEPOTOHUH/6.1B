#pragma once
#include "Vehicle.h"
#include <iostream>
#include <cstring>

class Car : public Vehicle {
    char* isTaxi;
public:
    Car(int red, int green, int blue, const char* num, const char* taxi,
        int x1, int y1, int x2, int y2);
    Car(const Car& other);
    Car& operator=(const Car& other);
    ~Car();

    // Getter
    const char* getIsTaxi() const;

    // Setter
    void setIsTaxi(const char* taxi);

    std::ostream& Print(std::ostream& os) const override;
};