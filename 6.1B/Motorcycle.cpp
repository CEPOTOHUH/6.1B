#include "Motorcycle.h"
#include <iostream> 

// Ðåàëèçàöèÿ ìåòîäîâ Motorcycle
Motorcycle::Motorcycle() : Vehicle() {}
Motorcycle::Motorcycle(int x1, int y1, int x2, int y2, int color, const char* plate)
    : Vehicle(x1, y1, x2, y2, color, plate) {
}
void Motorcycle::print(std::ostream& os) const {
    os << "--- Ìîòîöèêë ---\n";
    Vehicle::print(os);
}
void Motorcycle::inputInfo() {
    std::cout << "--- Ââîä äàííûõ Ìîòîöèêëà ---\n";
    Vehicle::inputInfo();
}
