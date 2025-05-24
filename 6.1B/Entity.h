#pragma once
#include <iostream>
#include <stdexcept>

class Entity {
protected:
    int xmin, ymin, xmax, ymax;
public:
    Entity(int x1, int y1, int x2, int y2);
    virtual ~Entity() = default;

    // Getters
    int getXmin() const;
    int getYmin() const;
    int getXmax() const;
    int getYmax() const;

    // Setter for all coordinates with validation
    void setBoundingBox(int x1, int y1, int x2, int y2);

    virtual std::ostream& Print(std::ostream& os) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Entity& e);
};