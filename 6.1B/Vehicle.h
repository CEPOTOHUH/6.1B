#pragma once
#include "Entity.h"
#include <cstring>

class Vehicle : public Entity {
protected:
    int r, g, b;
    char* number;
public:
    Vehicle(int red, int green, int blue, const char* num, int x1, int y1, int x2, int y2);
    Vehicle(const Vehicle& other);
    Vehicle& operator=(const Vehicle& other);
    virtual ~Vehicle();

    // Getters
    int getR() const;
    int getG() const;
    int getB() const;
    const char* getNumber() const;

    // Setters
    void setColor(int red, int green, int blue); // С валидацией 0-255
    void setNumber(const char* num);
};