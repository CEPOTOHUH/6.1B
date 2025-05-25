#include "Cyclist.h"

// Реализация конструкторов
Cyclist::Cyclist() : Person() {}

Cyclist::Cyclist(int x1, int y1, int x2, int y2,
    int g, int c, int gl, int b)
    : Person(x1, y1, x2, y2, g, c, gl, b) {
}

// Реализация методов print и inputInfo
void Cyclist::print(std::ostream& os) const {
    os << "--- Велосипедист ---\n";
    Person::print(os); // Вызываем метод базового класса
}

void Cyclist::inputInfo() {
    std::cout << "--- Ввод данных Велосипедиста ---\n";
    Person::inputInfo(); // Вызываем метод базового класса
}

// Правило Пяти (дефолтные реализации)
Cyclist::Cyclist(const Cyclist& other) = default;
Cyclist& Cyclist::operator=(const Cyclist& other) = default;
Cyclist::Cyclist(Cyclist&& other) noexcept = default;
Cyclist& Cyclist::operator=(Cyclist&& other) noexcept = default;