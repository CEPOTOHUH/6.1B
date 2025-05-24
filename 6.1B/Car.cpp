#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"
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

Car::Car(int red, int green, int blue, const char* num, const char* taxi_status,
    int x1, int y1, int x2, int y2)
    : Vehicle(red, green, blue, num, x1, y1, x2, y2) {
    isTaxi = nullptr; // Инициализация перед вызовом сеттера
    setIsTaxi(taxi_status);
}

Car::Car(const Car& other) : Vehicle(other) {
    isTaxi = safe_strdup_cpp(other.isTaxi);
}

Car& Car::operator=(const Car& other) {
    if (this != &other) {
        Vehicle::operator=(other);
        setIsTaxi(other.isTaxi);
    }
    return *this;
}

Car::~Car() {
    delete[] isTaxi;
}

// Getter
const char* Car::getIsTaxi() const { return isTaxi; }

// Setter
void Car::setIsTaxi(const char* taxi_status) {
    delete[] isTaxi;
    isTaxi = safe_strdup_cpp(taxi_status);
}

std::ostream& Car::Print(std::ostream& os) const {
    os << "[Car] Coords: (" << getXmin() << "," << getYmin() << ")-(" << getXmax() << "," << getYmax() << ") ";
    os << "Color: RGB(" << getR() << "," << getG() << "," << getB() << "), Number: " << (getNumber() ? getNumber() : "N/A")
        << ", Taxi: " << (getIsTaxi() ? getIsTaxi() : "N/A");
    return os;
}