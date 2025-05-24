#include "Entity.h"

Entity::Entity(int x1, int y1, int x2, int y2) {
    setBoundingBox(x1, y1, x2, y2); // Use setter for initial validation
}

// Getters
int Entity::getXmin() const { return xmin; }
int Entity::getYmin() const { return ymin; }
int Entity::getXmax() const { return xmax; }
int Entity::getYmax() const { return ymax; }

// Setter
void Entity::setBoundingBox(int x1, int y1, int x2, int y2) {
    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || x1 > x2 || y1 > y2)
        throw std::invalid_argument("Invalid coordinates for Entity: ensure x1 <= x2, y1 <= y2 and all >= 0.");
    xmin = x1;
    ymin = y1;
    xmax = x2;
    ymax = y2;
}

std::ostream& operator<<(std::ostream& os, const Entity& e) {
    return e.Print(os);
}