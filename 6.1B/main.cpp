#include "DetectedObject.h"
#include "Person.h"
#include "Cyclist.h"
#include "Vehicle.h"
#include "Motorcycle.h"
#include "Car.h"
#include "UnattendedBag.h"
#include <locale> // Для setlocale

void inputObjectInfo(DetectedObject* obj) {
    if (obj) {
        obj->inputInfo();
        std::cout << "---------------------------------\n";
    }
    else {
        std::cout << "Объект не существует.\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "Демонстрация иерархии классов (с ручным управлением C-строками и Правилом Пяти):\n\n";

    DetectedObject* myDetectedObject = nullptr;
    char choice;

    std::cout << "Выберите тип объекта для ввода и вывода:\n";
    std::cout << "1. Человек\n";
    std::cout << "2. Велосипедист\n";
    std::cout << "3. Автомобиль\n";
    std::cout << "4. Мотоцикл\n";
    std::cout << "5. Бесхозная сумка\n";
    std::cout << "Ваш выбор: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер ввода

    switch (choice) {
    case '1': myDetectedObject = new Person(); break;
    case '2': myDetectedObject = new Cyclist(); break;
    case '3': myDetectedObject = new Car(); break;
    case '4': myDetectedObject = new Motorcycle(); break;
    case '5': myDetectedObject = new UnattendedBag(); break;
    default:
        std::cout << "Неверный выбор. Программа завершится.\n";
        return 1;
    }

    std::cout << "\n--- Ввод данных для выбранного объекта ---\n";
    inputObjectInfo(myDetectedObject);

    std::cout << "\n--- Отображение информации для введенного объекта ---\n";
    std::cout << *myDetectedObject << std::endl;
    std::cout << "---------------------------------\n";

    delete myDetectedObject;
    myDetectedObject = nullptr;

    std::cout << "\nПрограмма завершена.\n";

    return 0;
}