#include "Motorcycle.h"

Motorcycle::Motorcycle(int red, int green, int blue, const char* num,
    int x1, int y1, int x2, int y2)
    : Vehicle(red, green, blue, num, x1, y1, x2, y2) {
}

std::ostream& Motorcycle::Print(std::ostream& os) const {
    os << "[Motorcycle] Coords: (" << getXmin() << "," << getYmin() << ")-(" << getXmax() << "," << getYmax() << ") ";
    os << "Color: RGB(" << getR() << "," << getG() << "," << getB() << "), Number: " << (getNumber() ? getNumber() : "N/A");
    return os;
}