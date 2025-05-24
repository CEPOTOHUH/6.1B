#include "Cyclist.h"

Cyclist::Cyclist(const char* g, const char* child, const char* glasses, const char* beard,
    int x1, int y1, int x2, int y2)
    : Human(g, child, glasses, beard, x1, y1, x2, y2) {
}

std::ostream& Cyclist::Print(std::ostream& os) const {
    os << "[Cyclist] Coords: (" << getXmin() << "," << getYmin() << ")-(" << getXmax() << "," << getYmax() << ") ";
    os << "Gender: " << (getGender() ? getGender() : "N/A")
        << ", Child: " << (getIsChild() ? getIsChild() : "N/A")
        << ", Glasses: " << (getHasGlasses() ? getHasGlasses() : "N/A")
        << ", Beard: " << (getHasBeard() ? getHasBeard() : "N/A");
    return os;
}