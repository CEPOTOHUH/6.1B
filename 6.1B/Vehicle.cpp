#define _CRT_SECURE_NO_WARNINGS
#include "Vehicle.h"
#include <cstring> // ��� strcpy, strlen

// ���������� �������������
Vehicle::Vehicle() : DetectedObject(), colorRGB(0), licensePlate(nullptr), licensePlateLength(0), licensePlateCapacity(0) {}

Vehicle::Vehicle(int x1, int y1, int x2, int y2, int color, const char* plate)
    : DetectedObject(x1, y1, x2, y2), colorRGB(color) {
    if (plate != nullptr) {
        licensePlateLength = std::strlen(plate);
        licensePlateCapacity = licensePlateLength + 1;
        licensePlate = new char[licensePlateCapacity];
        std::strcpy(licensePlate, plate);
    }
    else {
        licensePlate = nullptr;
        licensePlateLength = 0;
        licensePlateCapacity = 0;
    }
}

// ���������� �����������
Vehicle::~Vehicle() {
    if (licensePlate != nullptr) {
        delete[] licensePlate;
        licensePlate = nullptr;
        licensePlateLength = 0;
        licensePlateCapacity = 0;
    }
}

// ���������� ������������ �����������
Vehicle::Vehicle(const Vehicle& other)
    : DetectedObject(other),
    colorRGB(other.colorRGB),
    licensePlate(nullptr), licensePlateLength(0), licensePlateCapacity(0) {
    if (other.licensePlate != nullptr) {
        licensePlateLength = other.licensePlateLength;
        licensePlateCapacity = other.licensePlateCapacity;
        licensePlate = new char[licensePlateCapacity];
        std::strcpy(licensePlate, other.licensePlate);
    }
}

// ���������� ��������� ������������ ������������
Vehicle& Vehicle::operator=(const Vehicle& other) {
    if (this != &other) {
        DetectedObject::operator=(other);
        colorRGB = other.colorRGB;

        if (licensePlate != nullptr) {
            delete[] licensePlate;
            licensePlate = nullptr;
            licensePlateLength = 0;
            licensePlateCapacity = 0;
        }

        if (other.licensePlate != nullptr) {
            licensePlateLength = other.licensePlateLength;
            licensePlateCapacity = other.licensePlateCapacity;
            licensePlate = new char[licensePlateCapacity];
            std::strcpy(licensePlate, other.licensePlate);
        }
    }
    return *this;
}

// ���������� ������������ �����������
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

// ���������� ��������� ������������ ������������
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
        other.licensePlateCapacity = 0;
        other.colorRGB = 0;
    }
    return *this;
}

// ���������� ������ print
void Vehicle::print(std::ostream& os) const {
    os << "--- ������������ �������� ---\n";
    DetectedObject::print(os);
    os << "  ���� (RGB hex): 0x" << std::hex << colorRGB << std::dec << "\n";
    os << "  �����: " << (licensePlate ? licensePlate : "�� ���.") << "\n";
}

// ���������� ������ inputInfo
void Vehicle::inputInfo() {
    std::cout << "--- ���� ������ ������������� �������� ---\n";
    DetectedObject::inputInfo();
    std::cout << "  ������� ���� (RGB hex, ��������, FF0000 ��� ��������): 0x"; std::cin >> std::hex >> colorRGB >> std::dec;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "  ������� �����: ";

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
            std::memcpy(new_buffer, buffer, current_length); // ���������� memcpy ��� �����������
            delete[] buffer;
            buffer = new_buffer;
        }
        buffer[current_length++] = c;
    }
    buffer[current_length] = '\0';

    licensePlate = buffer;
    licensePlateLength = current_length;
    licensePlateCapacity = current_capacity;
}

// ���������� ������ setLicensePlate
void Vehicle::setLicensePlate(const char* newPlate) {
    if (licensePlate != nullptr) {
        delete[] licensePlate;
        licensePlate = nullptr;
        licensePlateLength = 0;
        licensePlateCapacity = 0;
    }

    if (newPlate != nullptr) {
        licensePlateLength = std::strlen(newPlate);
        licensePlateCapacity = licensePlateLength + 1;
        licensePlate = new char[licensePlateCapacity];
        std::strcpy(licensePlate, newPlate);
    }
}