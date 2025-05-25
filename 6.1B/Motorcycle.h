

#include "Vehicle.h" // Включаем базовый класс

class Motorcycle : public Vehicle {
public:
    Motorcycle();
    Motorcycle(int x1, int y1, int x2, int y2, int color, const char* plate);
    ~Motorcycle() override = default;

    // Правило Пяти
    Motorcycle(const Motorcycle& other);
    Motorcycle& operator=(const Motorcycle& other);
    Motorcycle(Motorcycle&& other) noexcept;
    Motorcycle& operator=(Motorcycle&& other) noexcept;

    void print(std::ostream& os) const override;
    void inputInfo() override;
};
