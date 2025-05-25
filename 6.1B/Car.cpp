#include "Car.h"

// Реализация конструкторов
Car::Car() : Vehicle(), isTaxi(false) {}

Car::Car(int x1, int y1, int x2, int y2, int color, const char* plate, bool taxi)
    : Vehicle(x1, y1, x2, y2, color, plate), isTaxi(taxi) {
}

// Реализация методов print и inputInfo
void Car::print(std::ostream& os) const {
    os << "--- Автомобиль ---\n";
    Vehicle::print(os); // Вызываем метод базового класса
    os << "  Такси (0=Нет, 1=Да): " << (isTaxi ? "Да" : "Нет") << "\n";
}

void Car::inputInfo() {
    std::cout << "--- Ввод данных Автомобиля ---\n";
    Vehicle::inputInfo(); // Вызываем метод базового класса
    std::cout << "  Такси (0=Нет, 1=Да): "; std::cin >> isTaxi;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Правило Пяти (дефолтные реализации)
Car::Car(const Car& other) = default;
Car& Car::operator=(const Car& other) = default;
Car::Car(Car&& other) noexcept = default;
Car& Car::operator=(Car&& other) noexcept = default;