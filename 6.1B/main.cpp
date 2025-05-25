#include "DetectedObject.h"
#include "Person.h"
#include "Cyclist.h"
#include "Vehicle.h"
#include "Motorcycle.h"
#include "Car.h"
#include "UnattendedBag.h"
#include <locale> // ��� setlocale

void inputObjectInfo(DetectedObject* obj) {
    if (obj) {
        obj->inputInfo();
        std::cout << "---------------------------------\n";
    }
    else {
        std::cout << "������ �� ����������.\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "������������ �������� ������� (� ������ ����������� C-�������� � �������� ����):\n\n";

    DetectedObject* myDetectedObject = nullptr;
    char choice;

    std::cout << "�������� ��� ������� ��� ����� � ������:\n";
    std::cout << "1. �������\n";
    std::cout << "2. ������������\n";
    std::cout << "3. ����������\n";
    std::cout << "4. ��������\n";
    std::cout << "5. ��������� �����\n";
    std::cout << "��� �����: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ����� �����

    switch (choice) {
    case '1': myDetectedObject = new Person(); break;
    case '2': myDetectedObject = new Cyclist(); break;
    case '3': myDetectedObject = new Car(); break;
    case '4': myDetectedObject = new Motorcycle(); break;
    case '5': myDetectedObject = new UnattendedBag(); break;
    default:
        std::cout << "�������� �����. ��������� ����������.\n";
        return 1;
    }

    std::cout << "\n--- ���� ������ ��� ���������� ������� ---\n";
    inputObjectInfo(myDetectedObject);

    std::cout << "\n--- ����������� ���������� ��� ���������� ������� ---\n";
    std::cout << *myDetectedObject << std::endl;
    std::cout << "---------------------------------\n";

    delete myDetectedObject;
    myDetectedObject = nullptr;

    std::cout << "\n��������� ���������.\n";

    return 0;
}