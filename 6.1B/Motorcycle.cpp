#include "Motorcycle.h"

// Реализация конструкторов
Motorcycle::Motorcycle() : Vehicle() {}

Motorcycle::Motorcycle(int x1, int y1, int x2, int y2, int color, const char* plate)
    : Vehicle(x1, y1, x2, y2, color, plate) {
}

// Реализация методов print и inputInfo
void Motorcycle::print(std::ostream& os) const {
    os << "--- Мотоцикл ---\n";
    Vehicle::print(os); // Вызываем метод базового класса
}

void Motorcycle::inputInfo() {
    std::cout << "--- Ввод данных Мотоцикла ---\n";
    Vehicle::inputInfo(); // Вызываем метод базового класса
}

// Правило Пяти (дефолтные реализации)
Motorcycle::Motorcycle(const Motorcycle& other) = default;
Motorcycle& Motorcycle::operator=(const Motorcycle& other) = default;
Motorcycle::Motorcycle(Motorcycle&& other) noexcept = default;
Motorcycle& Motorcycle::operator=(Motorcycle&& other) noexcept = default;