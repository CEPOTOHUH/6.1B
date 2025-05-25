#include "UnattendedBag.h"

// Реализация конструкторов
UnattendedBag::UnattendedBag() : DetectedObject(), detectedTimeSeconds(0) {}

UnattendedBag::UnattendedBag(int x1, int y1, int x2, int y2, long long time)
    : DetectedObject(x1, y1, x2, y2), detectedTimeSeconds(time) {
}

// Реализация методов print и inputInfo
void UnattendedBag::print(std::ostream& os) const {
    os << "--- Бесхозная сумка ---\n";
    DetectedObject::print(os); // Вызываем метод базового класса
    os << "  Время первого обнаружения (секунды после полуночи): " << detectedTimeSeconds << "\n";
}

void UnattendedBag::inputInfo() {
    std::cout << "--- Ввод данных Бесхозной сумки ---\n";
    DetectedObject::inputInfo(); // Вызываем метод базового класса
    std::cout << "  Введите время первого обнаружения (секунды после полуночи): "; std::cin >> detectedTimeSeconds;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Правило Пяти (дефолтные реализации)
UnattendedBag::UnattendedBag(const UnattendedBag& other) = default;
UnattendedBag& UnattendedBag::operator=(const UnattendedBag& other) = default;
UnattendedBag::UnattendedBag(UnattendedBag&& other) noexcept = default;
UnattendedBag& UnattendedBag::operator=(UnattendedBag&& other) noexcept = default;