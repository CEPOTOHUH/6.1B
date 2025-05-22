#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stdexcept>

class Entity {
protected:
    int xmin, ymin, xmax, ymax;
public:
    Entity(int x1, int y1, int x2, int y2) : xmin(x1), ymin(y1), xmax(x2), ymax(y2) {
        if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || x1 > x2 || y1 > y2)
            throw std::invalid_argument("Invalid coordinates");
    }
    virtual ~Entity() = default;
    virtual std::ostream& Print(std::ostream& os) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Entity& e) {
        return e.Print(os);
    }
};

class Human : public Entity {
protected:
    char* gender;
    char* isChild;
    char* hasGlasses;
    char* hasBeard;
public:
    Human(const char* g, const char* child, const char* glasses, const char* beard,
        int x1, int y1, int x2, int y2)
        : Entity(x1, y1, x2, y2)
    {
        gender = _strdup(g);
        isChild = _strdup(child);
        hasGlasses = _strdup(glasses);
        hasBeard = _strdup(beard);
    }

    Human(const Human& other) : Entity(other.xmin, other.ymin, other.xmax, other.ymax) {
        gender = _strdup(other.gender);
        isChild = _strdup(other.isChild);
        hasGlasses = _strdup(other.hasGlasses);
        hasBeard = _strdup(other.hasBeard);
    }

    Human& operator=(const Human& other) {
        if (this != &other) {
            xmin = other.xmin; ymin = other.ymin; xmax = other.xmax; ymax = other.ymax;
            delete[] gender;
            delete[] isChild;
            delete[] hasGlasses;
            delete[] hasBeard;
            gender = _strdup(other.gender);
            isChild = _strdup(other.isChild);
            hasGlasses = _strdup(other.hasGlasses);
            hasBeard = _strdup(other.hasBeard);
        }
        return *this;
    }

    virtual ~Human() {
        delete[] gender;
        delete[] isChild;
        delete[] hasGlasses;
        delete[] hasBeard;
    }
};

class Person : public Human {
public:
    Person(const char* g, const char* child, const char* glasses, const char* beard,
        int x1, int y1, int x2, int y2)
        : Human(g, child, glasses, beard, x1, y1, x2, y2) {
    }

    std::ostream& Print(std::ostream& os) const override {
        os << "[Person] Coords: (" << xmin << "," << ymin << ")-(" << xmax << "," << ymax << ") ";
        os << "Gender: " << gender << ", Child: " << isChild
            << ", Glasses: " << hasGlasses << ", Beard: " << hasBeard;
        return os;
    }
};

class Cyclist : public Human {
public:
    Cyclist(const char* g, const char* child, const char* glasses, const char* beard,
        int x1, int y1, int x2, int y2)
        : Human(g, child, glasses, beard, x1, y1, x2, y2) {
    }

    std::ostream& Print(std::ostream& os) const override {
        os << "[Cyclist] Coords: (" << xmin << "," << ymin << ")-(" << xmax << "," << ymax << ") ";
        os << "Gender: " << gender << ", Child: " << isChild
            << ", Glasses: " << hasGlasses << ", Beard: " << hasBeard;
        return os;
    }
};

class Vehicle : public Entity {
protected:
    int r, g, b;
    char* number;
public:
    Vehicle(int red, int green, int blue, const char* num, int x1, int y1, int x2, int y2)
        : Entity(x1, y1, x2, y2), r(red), g(green), b(blue) {
        number = _strdup(num);
    }

    Vehicle(const Vehicle& other) : Entity(other.xmin, other.ymin, other.xmax, other.ymax),
        r(other.r), g(other.g), b(other.b) {
        number = _strdup(other.number);
    }

    Vehicle& operator=(const Vehicle& other) {
        if (this != &other) {
            xmin = other.xmin; ymin = other.ymin; xmax = other.xmax; ymax = other.ymax;
            r = other.r; g = other.g; b = other.b;
            delete[] number;
            number = _strdup(other.number);
        }
        return *this;
    }

    virtual ~Vehicle() {
        delete[] number;
    }
};

class Car : public Vehicle {
    char* isTaxi;
public:
    Car(int red, int green, int blue, const char* num, const char* taxi,
        int x1, int y1, int x2, int y2)
        : Vehicle(red, green, blue, num, x1, y1, x2, y2) {
        isTaxi = _strdup(taxi);
    }

    Car(const Car& other) : Vehicle(other), isTaxi(_strdup(other.isTaxi)) {}

    Car& operator=(const Car& other) {
        if (this != &other) {
            Vehicle::operator=(other);
            delete[] isTaxi;
            isTaxi = _strdup(other.isTaxi);
        }
        return *this;
    }

    ~Car() {
        delete[] isTaxi;
    }

    std::ostream& Print(std::ostream& os) const override {
        os << "[Car] Coords: (" << xmin << "," << ymin << ")-(" << xmax << "," << ymax << ") ";
        os << "Color: RGB(" << r << "," << g << "," << b << "), Number: " << number
            << ", Taxi: " << isTaxi;
        return os;
    }
};

class Motorcycle : public Vehicle {
public:
    Motorcycle(int red, int green, int blue, const char* num,
        int x1, int y1, int x2, int y2)
        : Vehicle(red, green, blue, num, x1, y1, x2, y2) {
    }

    std::ostream& Print(std::ostream& os) const override {
        os << "[Motorcycle] Coords: (" << xmin << "," << ymin << ")-(" << xmax << "," << ymax << ") ";
        os << "Color: RGB(" << r << "," << g << "," << b << "), Number: " << number;
        return os;
    }
};

class UnattendedBag : public Entity {
    int timeSeen;
public:
    UnattendedBag(int x1, int y1, int x2, int y2, int time)
        : Entity(x1, y1, x2, y2), timeSeen(time) {
    }

    std::ostream& Print(std::ostream& os) const override {
        os << "[UnattendedBag] Coords: (" << xmin << "," << ymin << ")-(" << xmax << "," << ymax << ") ";
        os << "First seen at: " << timeSeen << " seconds since midnight";
        return os;
    }
};

int main() {
    try {
        const int max = 100;
        char gender[max], child[max], glasses[max], beard[max];
        int x1, y1, x2, y2;

        std::cout << "Enter person (gender, child, glasses, beard, x1 y1 x2 y2): ";
        std::cin >> gender >> child >> glasses >> beard >> x1 >> y1 >> x2 >> y2;
        Person person(gender, child, glasses, beard, x1, y1, x2, y2);

        std::cout << "Enter cyclist (gender, child, glasses, beard, x1 y1 x2 y2): ";
        std::cin >> gender >> child >> glasses >> beard >> x1 >> y1 >> x2 >> y2;
        Cyclist cyclist(gender, child, glasses, beard, x1, y1, x2, y2);

        char number[max], taxi[max];
        int r, g, b;
        std::cout << "Enter car (r g b number taxi x1 y1 x2 y2): ";
        std::cin >> r >> g >> b >> number >> taxi >> x1 >> y1 >> x2 >> y2;
        Car car(r, g, b, number, taxi, x1, y1, x2, y2);

        std::cout << "Enter motorcycle (r g b number x1 y1 x2 y2): ";
        std::cin >> r >> g >> b >> number >> x1 >> y1 >> x2 >> y2;
        Motorcycle moto(r, g, b, number, x1, y1, x2, y2);

        int time;
        std::cout << "Enter unattended bag (x1 y1 x2 y2 time): ";
        std::cin >> x1 >> y1 >> x2 >> y2 >> time;
        UnattendedBag bag(x1, y1, x2, y2, time);

        std::cout << "\n--- Detected Entities ---\n";
        std::cout << person << "\n" << cyclist << "\n" << car << "\n" << moto << "\n" << bag << "\n";

    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    return 0;
}
