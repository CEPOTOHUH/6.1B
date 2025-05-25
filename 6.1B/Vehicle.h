
#include "DetectedObject.h"
#include <cstdio> // Для size_t

class Vehicle : public DetectedObject {
protected:
    int colorRGB;
    char* licensePlate;
    size_t licensePlateLength;
    size_t licensePlateCapacity;

public:
    Vehicle();
    Vehicle(int x1, int y1, int x2, int y2, int color, const char* plate);
    virtual ~Vehicle() override;

    // Правило Пяти
    Vehicle(const Vehicle& other);
    Vehicle& operator=(const Vehicle& other);
    Vehicle(Vehicle&& other) noexcept;
    Vehicle& operator=(Vehicle&& other) noexcept;

    virtual void print(std::ostream& os) const override;
    virtual void inputInfo() override;

    void setLicensePlate(const char* newPlate);
};

