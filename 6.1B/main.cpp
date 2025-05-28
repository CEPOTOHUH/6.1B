#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <limits>  
#include <clocale>  

// Включаем заголовочные файлы всех классов
#include "DetectedObject.h"
#include "Person.h"
#include "Cyclist.h"
#include "Vehicle.h"
#include "Motorcycle.h"
#include "Car.h"
#include "UnattendedBag.h"

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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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

    // --- Демонстрация использования set/get методов ---
    std::cout << "\n--- Демонстрация использования set/get методов ---\n";
    if (myDetectedObject != nullptr) {
        // Полиморфные set/get для базовых координат
        std::cout << "Исходные Xmin: " << myDetectedObject->getXmin() << std::endl;
        myDetectedObject->setXmin(100);
        std::cout << "Новые Xmin: " << myDetectedObject->getXmin() << " (должно быть 100)\n";
        myDetectedObject->setXmin(-50); // Попытка установить невалидное значение
        std::cout << "Xmin после попытки установить невалидное: " << myDetectedObject->getXmin() << " (должно быть 100)\n";
        myDetectedObject->setXmax(10); // Попытка установить Xmax < Xmin
        std::cout << "Xmax после попытки установить Xmax < Xmin: " << myDetectedObject->getXmax() << " (должно быть исходное, не 10)\n";
        myDetectedObject->setXmax(200); // Валидная установка Xmax
        std::cout << "Xmax после валидной установки: " << myDetectedObject->getXmax() << " (должно быть 200)\n";

        // Демонстрация set/get для специфичных полей через dynamic_cast
        Person* p = dynamic_cast<Person*>(myDetectedObject);
        if (p) {
            std::cout << "\n--- Специфичные данные для Человека/Велосипедиста ---\n";
            std::cout << "Исходный пол человека: " << p->getGender() << std::endl;
            p->setGender(0); // Мужчина
            std::cout << "Новый пол человека: " << p->getGender() << " (должно быть 0)\n";
            p->setGender(5); // Попытка установить невалидное значение
            std::cout << "Пол после попытки установить невалидное: " << p->getGender() << " (должно быть 0)\n";
        }

        Car* c = dynamic_cast<Car*>(myDetectedObject);
        if (c) {
            std::cout << "\n--- Специфичные данные для Автомобиля ---\n";
            std::cout << "Автомобиль такси? " << (c->getIsTaxi() ? "Да" : "Нет") << std::endl;
            c->setIsTaxi(true);
            std::cout << "Автомобиль такси теперь? " << (c->getIsTaxi() ? "Да" : "Нет") << " (должно быть Да)\n";
            c->setIsTaxi(false); // Установка в false
            std::cout << "Автомобиль такси теперь? " << (c->getIsTaxi() ? "Да" : "Нет") << " (должно быть Нет)\n";
        }

        Motorcycle* m = dynamic_cast<Motorcycle*>(myDetectedObject); // Dynamic cast for Motorcycle
        if (m) {
            std::cout << "\n--- Специфичные данные для Мотоцикла (через Vehicle) ---\n";
            std::cout << "Цвет мотоцикла (RGB): 0x" << std::hex << m->getColorRGB() << std::dec << std::endl;
            m->setColorRGB(0x00FF00); 
            std::cout << "Новый цвет мотоцикла: 0x" << std::hex << m->getColorRGB() << std::dec << " (должен быть 0x00FF00)\n";
            std::cout << "Номерной знак мотоцикла: " << (m->getLicensePlate() ? m->getLicensePlate() : "Не опр.") << std::endl;
            m->setLicensePlate("MOTO888");
            std::cout << "Новый номерной знак мотоцикла: " << (m->getLicensePlate() ? m->getLicensePlate() : "Не опр.") << " (должен быть MOTO888)\n";
        }

        Vehicle* v = dynamic_cast<Vehicle*>(myDetectedObject);
        if (v && !c && !m) {
            std::cout << "\n--- Специфичные данные для Транспортного средства (если не Авто или Мото) ---\n";
            std::cout << "Цвет ТС (RGB): 0x" << std::hex << v->getColorRGB() << std::dec << std::endl;
            v->setColorRGB(0x0000FF); // Blue
            std::cout << "Новый цвет ТС: 0x" << std::hex << v->getColorRGB() << std::dec << " (должен быть 0x0000FF)\n";
            std::cout << "Номерной знак ТС: " << (v->getLicensePlate() ? v->getLicensePlate() : "Не опр.") << std::endl;
            v->setLicensePlate("GENERIC1");
            std::cout << "Новый номерной знак ТС: " << (v->getLicensePlate() ? v->getLicensePlate() : "Не опр.") << " (должен быть GENERIC1)\n";
        }


        UnattendedBag* ub = dynamic_cast<UnattendedBag*>(myDetectedObject);
        if (ub) {
            std::cout << "\n--- Специфичные данные для Бесхозной сумки ---\n";
            std::cout << "Время обнаружения бесхозной сумки: " << ub->getDetectedTimeSeconds() << std::endl;
            ub->setDetectedTimeSeconds(3600); // 1 час после полуночи
            std::cout << "Новое время обнаружения бесхозной сумки: " << ub->getDetectedTimeSeconds() << " (должно быть 3600)\n";
            ub->setDetectedTimeSeconds(90000); // Попытка установить невалидное время
            std::cout << "Время обнаружения после попытки установить невалидное: " << ub->getDetectedTimeSeconds() << " (должно быть 3600)\n";
        }

        std::cout << "\n--- Объект после изменения через set методы ---\n";
        std::cout << *myDetectedObject << std::endl;
    }
    std::cout << "---------------------------------\n";

    delete myDetectedObject;
    myDetectedObject = nullptr;

    std::cout << "\nПрограмма завершена.\n";

    return 0;
}