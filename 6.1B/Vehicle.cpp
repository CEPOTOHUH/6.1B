#define _CRT_SECURE_NO_WARNINGS
#include "Vehicle.h"
#include <cstring>
#include <stdexcept>

// Вспомогательная функция (аналогично Human.cpp)
static char* safe_strdup_cpp(const char* str) {
    if (!str) return nullptr;
    size_t len = strlen(str) + 1;
    char* new_str = new char[len];
    strcpy(new_str, str);
    return new_str;
}

Vehicle::Vehicle(int red, int green, int blue, const char* num, int x1, int y1, int x2, int y2)
    : Entity(x1, y1, x2, y2) {
    setColor(red, green, blue); // Используем сеттер для валидации
    number = nullptr; // Инициализация перед вызовом сеттера
    setNumber(num);
}

Vehicle::Vehicle(const Vehicle& other) : Entity(other) {
    setColor(other.r, other.g, other.b); // Копируем цвет (валидация не нужна, т.к. он уже валиден)
    r = other.r; g = other.g; b = other.b; // Прямое присваивание после валидации в конструкторе other
    number = safe_strdup_cpp(other.number);
}

Vehicle& Vehicle::operator=(const Vehicle& other) {
    if (this != &other) {
        Entity::operator=(other);
        setColor(other.r, other.g, other.b);
        setNumber(other.number);
    }
    return *this;
}

Vehicle::~Vehicle() {
    delete[] number;
}

// Getters
int Vehicle::getR() const { return r; }
int Vehicle::getG() const { return g; }
int Vehicle::getB() const { return b; }
const char* Vehicle::getNumber() const { return number; }

// Setters
void Vehicle::setColor(int red, int green, int blue) {
    if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255) {
        throw std::invalid_argument("Invalid RGB color value. Each component must be between 0 and 255.");
    }
    r = red;
    g = green;
    b = blue;
}

void Vehicle::setNumber(const char* num) {
    delete[] number;
    number = safe_strdup_cpp(num);
}