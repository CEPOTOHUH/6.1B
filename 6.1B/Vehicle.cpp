#define _CRT_SECURE_NO_WARNINGS
#include "Vehicle.h"
#include <iostream> 

Vehicle::Vehicle() : DetectedObject(), colorRGB(0), licensePlate(nullptr), licensePlateLength(0), licensePlateCapacity(0) {}

Vehicle::Vehicle(int x1, int y1, int x2, int y2, int color, const char* plate)
    : DetectedObject(x1, y1, x2, y2), colorRGB(color) {
    setLicensePlate(plate);
}
Vehicle::~Vehicle() {
    if (licensePlate != nullptr) {
        delete[] licensePlate;
        licensePlate = nullptr;
        licensePlateLength = 0;
        licensePlateCapacity = 0;
    }
}

Vehicle::Vehicle(const Vehicle& other)
    : DetectedObject(other), 
    colorRGB(other.colorRGB),
    licensePlate(nullptr), licensePlateLength(0), licensePlateCapacity(0) {
    setLicensePlate(other.licensePlate);
}

Vehicle& Vehicle::operator=(const Vehicle& other) {
    if (this != &other) { 
        DetectedObject::operator=(other); 
        colorRGB = other.colorRGB;
        setLicensePlate(other.licensePlate);
    }
    return *this;
}

Vehicle::Vehicle(Vehicle&& other) noexcept
    : DetectedObject(std::move(other)), 
    colorRGB(other.colorRGB),
    licensePlate(other.licensePlate),  
    licensePlateLength(other.licensePlateLength),
    licensePlateCapacity(other.licensePlateCapacity) {
    other.licensePlate = nullptr;
    other.licensePlateLength = 0;
    other.licensePlateCapacity = 0;
    other.colorRGB = 0; 
}

Vehicle& Vehicle::operator=(Vehicle&& other) noexcept {
    if (this != &other) { 
        DetectedObject::operator=(std::move(other));

        if (licensePlate != nullptr) {
            delete[] licensePlate;
        }

        licensePlate = other.licensePlate;
        licensePlateLength = other.licensePlateLength;
        licensePlateCapacity = other.licensePlateCapacity;
        colorRGB = other.colorRGB;
        other.licensePlate = nullptr;
        other.licensePlateLength = 0;
        other.colorRGB = 0;
    }
    return *this;
}

void Vehicle::print(std::ostream& os) const {
    os << "--- Транспортное средство ---\n";
    DetectedObject::print(os);
    os << "  Цвет (RGB hex): 0x" << std::hex << colorRGB << std::dec << "\n";
    os << "  Номер: " << (licensePlate ? licensePlate : "Не опр.") << "\n";
}

void Vehicle::inputInfo() {
    std::cout << "--- Ввод данных Транспортного средства ---\n";
    DetectedObject::inputInfo();
    std::cout << "  Введите цвет (RGB hex, например, FF0000 для красного): 0x";
    std::cin >> std::hex >> colorRGB >> std::dec;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "  Введите номер: ";
    if (licensePlate != nullptr) {
        delete[] licensePlate;
        licensePlate = nullptr;
        licensePlateLength = 0;
        licensePlateCapacity = 0;
    }

    const size_t INITIAL_BUFFER_SIZE = 64;
    char* buffer = new char[INITIAL_BUFFER_SIZE];
    size_t current_capacity = INITIAL_BUFFER_SIZE;
    size_t current_length = 0;
    char c;

    while (std::cin.get(c) && c != '\n' && std::cin.good()) {
        if (current_length + 1 >= current_capacity) { 
            current_capacity *= 2;
            char* new_buffer = new char[current_capacity];
            for (size_t i = 0; i < current_length; ++i) {
                new_buffer[i] = buffer[i];
            }
            delete[] buffer; 
            buffer = new_buffer;
        }
        buffer[current_length++] = c;
    }
    buffer[current_length] = '\0'; 

    setLicensePlate(buffer);
    delete[] buffer; 
}

void Vehicle::setLicensePlate(const char* newPlate) {
    if (newPlate == nullptr || strlen(newPlate) == 0) {
        std::cerr << "Ошибка: Номерной знак не может быть пустым или NULL. Значение не изменено.\n";
        return;
    }

    size_t newLength = strlen(newPlate);

    if (licensePlateCapacity <= newLength) {
        if (licensePlate != nullptr) {
            delete[] licensePlate; 
        }
        licensePlateCapacity = newLength + 1; 
        licensePlate = new char[licensePlateCapacity];
    }
    strcpy(licensePlate, newPlate);
    licensePlateLength = newLength;
}
const char* Vehicle::getLicensePlate() const {
    return licensePlate;
}

void Vehicle::setColorRGB(int color) {
    colorRGB = color;
}
int Vehicle::getColorRGB() const {
    return colorRGB;
}