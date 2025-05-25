

#include "Vehicle.h" // Включаем базовый класс

class Car : public Vehicle {
private:
    bool isTaxi;

public:
    Car();
    Car(int x1, int y1, int x2, int y2, int color, const char* plate, bool taxi);
    ~Car() override = default;

    // Правило Пяти
    Car(const Car& other);
    Car& operator=(const Car& other);
    Car(Car&& other) noexcept;
    Car& operator=(Car&& other) noexcept;

    void print(std::ostream& os) const override;
    void inputInfo() override;
};
