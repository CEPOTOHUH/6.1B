#include "Motorcycle.h"
#include <iostream> // Для std::cout

// Реализация методов Motorcycle
Motorcycle::Motorcycle() : Vehicle() {}
Motorcycle::Motorcycle(int x1, int y1, int x2, int y2, int color, const char* plate)
    : Vehicle(x1, y1, x2, y2, color, plate) {
}

// Destructor is defaulted in .h
// Copy Constructor is defaulted in .h
// Copy Assignment Operator is defaulted in .h
// Move Constructor is defaulted in .h
// Move Assignment Operator is defaulted in .h

// CORRECTED: 'override' removed from the definition here
void Motorcycle::print(std::ostream& os) const {
    os << "--- Мотоцикл ---\n";
    Vehicle::print(os);
}

// CORRECTED: 'override' removed from the definition here
void Motorcycle::inputInfo() {
    std::cout << "--- Ввод данных Мотоцикла ---\n";
    Vehicle::inputInfo();
}