#include "Person.h"

// Реализация конструкторов
Person::Person() : DetectedObject(), gender(2), childStatus(2), glassesStatus(2), beardStatus(2) {}

Person::Person(int x1, int y1, int x2, int y2,
    int g, int c, int gl, int b)
    : DetectedObject(x1, y1, x2, y2), gender(g), childStatus(c), glassesStatus(gl), beardStatus(b) {
}

// Реализация методов print и inputInfo
void Person::print(std::ostream& os) const {
    os << "--- Человек ---\n";
    DetectedObject::print(os);
    os << "  Пол (0=Муж, 1=Жен, 2=Не опр.): " << gender << "\n";
    os << "  Ребёнок (0=Да, 1=Нет, 2=Не опр.): " << childStatus << "\n";
    os << "  Очки (0=Есть, 1=Нет, 2=Не опр.): " << glassesStatus << "\n";
    os << "  Борода (0=Есть, 1=Нет, 2=Не опр.): " << beardStatus << "\n";
}

void Person::inputInfo() {
    std::cout << "--- Ввод данных Человека ---\n";
    DetectedObject::inputInfo();
    std::cout << "  Введите пол (0=Муж, 1=Жен, 2=Не опр.): "; std::cin >> gender;
    std::cout << "  Введите статус ребёнка (0=Да, 1=Нет, 2=Не опр.): "; std::cin >> childStatus;
    std::cout << "  Введите статус очков (0=Есть, 1=Нет, 2=Не опр.): "; std::cin >> glassesStatus;
    std::cout << "  Введите статус бороды (0=Есть, 1=Нет, 2=Не опр.): "; std::cin >> beardStatus;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Правило Пяти (дефолтные реализации)
Person::Person(const Person& other) = default;
Person& Person::operator=(const Person& other) = default;
Person::Person(Person&& other) noexcept = default;
Person& Person::operator=(Person&& other) noexcept = default;