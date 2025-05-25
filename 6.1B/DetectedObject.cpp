#include "DetectedObject.h"

// Реализация конструкторов структуры Coordinates
DetectedObject::Coordinates::Coordinates() : Xmin(0), Ymin(0), Xmax(0), Ymax(0) {}

DetectedObject::Coordinates::Coordinates(int x1, int y1, int x2, int y2)
    : Xmin(x1), Ymin(y1), Xmax(x2), Ymax(y2) {
}

// Реализация конструкторов класса DetectedObject
DetectedObject::DetectedObject() : coordinates() {}

DetectedObject::DetectedObject(int x1, int y1, int x2, int y2)
    : coordinates(x1, y1, x2, y2) {
}

// Реализация методов print и inputInfo
void DetectedObject::print(std::ostream& os) const {
    os << "  Координаты: (" << coordinates.Xmin << ", " << coordinates.Ymin
        << ") - (" << coordinates.Xmax << ", " << coordinates.Ymax << ")\n";
}

void DetectedObject::inputInfo() {
    std::cout << "  Введите Xmin: "; std::cin >> coordinates.Xmin;
    std::cout << "  Введите Ymin: "; std::cin >> coordinates.Ymin;
    std::cout << "  Введите Xmax: "; std::cin >> coordinates.Xmax;
    std::cout << "  Введите Ymax: "; std::cin >> coordinates.Ymax;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Реализация перегрузки оператора <<
std::ostream& operator<<(std::ostream& os, const DetectedObject& obj) {
    obj.print(os);
    return os;
}

// Правило Пяти (дефолтные реализации, так как члены данных простые)
DetectedObject::DetectedObject(const DetectedObject& other) = default;
DetectedObject& DetectedObject::operator=(const DetectedObject& other) = default;
DetectedObject::DetectedObject(DetectedObject&& other) noexcept = default;
DetectedObject& DetectedObject::operator=(DetectedObject&& other) noexcept = default;