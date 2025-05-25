
#include "DetectedObject.h" // Включаем базовый класс

class Person : public DetectedObject {
private:
    int gender;
    int childStatus;
    int glassesStatus;
    int beardStatus;

public:
    Person();
    Person(int x1, int y1, int x2, int y2,
        int g, int c, int gl, int b);
    ~Person() override = default;

    // Правило Пяти
    Person(const Person& other);
    Person& operator=(const Person& other);
    Person(Person&& other) noexcept;
    Person& operator=(Person&& other) noexcept;

    void print(std::ostream& os) const override;
    void inputInfo() override;
};

