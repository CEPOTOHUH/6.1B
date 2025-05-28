#pragma once

#include "Vehicle.h" 

class Car : public Vehicle {
private:
    bool isTaxi;

public:
    Car();
    Car(int x1, int y1, int x2, int y2, int color, const char* plate, bool taxi);
    ~Car() override = default;
    Car(const Car& other) = default;
    Car& operator=(const Car& other) = default;
    Car(Car&& other) noexcept = default;
    Car& operator=(Car&& other) noexcept = default;

    void print(std::ostream& os) const override;
    void inputInfo() override;

    void setIsTaxi(bool taxi);
    bool getIsTaxi() const;
};