#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <limits>  
#include <clocale>  

// �������� ������������ ����� ���� �������
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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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

    // --- ������������ ������������� set/get ������� ---
    std::cout << "\n--- ������������ ������������� set/get ������� ---\n";
    if (myDetectedObject != nullptr) {
        // ����������� set/get ��� ������� ���������
        std::cout << "�������� Xmin: " << myDetectedObject->getXmin() << std::endl;
        myDetectedObject->setXmin(100);
        std::cout << "����� Xmin: " << myDetectedObject->getXmin() << " (������ ���� 100)\n";
        myDetectedObject->setXmin(-50); // ������� ���������� ���������� ��������
        std::cout << "Xmin ����� ������� ���������� ����������: " << myDetectedObject->getXmin() << " (������ ���� 100)\n";
        myDetectedObject->setXmax(10); // ������� ���������� Xmax < Xmin
        std::cout << "Xmax ����� ������� ���������� Xmax < Xmin: " << myDetectedObject->getXmax() << " (������ ���� ��������, �� 10)\n";
        myDetectedObject->setXmax(200); // �������� ��������� Xmax
        std::cout << "Xmax ����� �������� ���������: " << myDetectedObject->getXmax() << " (������ ���� 200)\n";

        // ������������ set/get ��� ����������� ����� ����� dynamic_cast
        Person* p = dynamic_cast<Person*>(myDetectedObject);
        if (p) {
            std::cout << "\n--- ����������� ������ ��� ��������/������������� ---\n";
            std::cout << "�������� ��� ��������: " << p->getGender() << std::endl;
            p->setGender(0); // �������
            std::cout << "����� ��� ��������: " << p->getGender() << " (������ ���� 0)\n";
            p->setGender(5); // ������� ���������� ���������� ��������
            std::cout << "��� ����� ������� ���������� ����������: " << p->getGender() << " (������ ���� 0)\n";
        }

        Car* c = dynamic_cast<Car*>(myDetectedObject);
        if (c) {
            std::cout << "\n--- ����������� ������ ��� ���������� ---\n";
            std::cout << "���������� �����? " << (c->getIsTaxi() ? "��" : "���") << std::endl;
            c->setIsTaxi(true);
            std::cout << "���������� ����� ������? " << (c->getIsTaxi() ? "��" : "���") << " (������ ���� ��)\n";
            c->setIsTaxi(false); // ��������� � false
            std::cout << "���������� ����� ������? " << (c->getIsTaxi() ? "��" : "���") << " (������ ���� ���)\n";
        }

        Motorcycle* m = dynamic_cast<Motorcycle*>(myDetectedObject); // Dynamic cast for Motorcycle
        if (m) {
            std::cout << "\n--- ����������� ������ ��� ��������� (����� Vehicle) ---\n";
            std::cout << "���� ��������� (RGB): 0x" << std::hex << m->getColorRGB() << std::dec << std::endl;
            m->setColorRGB(0x00FF00); 
            std::cout << "����� ���� ���������: 0x" << std::hex << m->getColorRGB() << std::dec << " (������ ���� 0x00FF00)\n";
            std::cout << "�������� ���� ���������: " << (m->getLicensePlate() ? m->getLicensePlate() : "�� ���.") << std::endl;
            m->setLicensePlate("MOTO888");
            std::cout << "����� �������� ���� ���������: " << (m->getLicensePlate() ? m->getLicensePlate() : "�� ���.") << " (������ ���� MOTO888)\n";
        }

        Vehicle* v = dynamic_cast<Vehicle*>(myDetectedObject);
        if (v && !c && !m) {
            std::cout << "\n--- ����������� ������ ��� ������������� �������� (���� �� ���� ��� ����) ---\n";
            std::cout << "���� �� (RGB): 0x" << std::hex << v->getColorRGB() << std::dec << std::endl;
            v->setColorRGB(0x0000FF); // Blue
            std::cout << "����� ���� ��: 0x" << std::hex << v->getColorRGB() << std::dec << " (������ ���� 0x0000FF)\n";
            std::cout << "�������� ���� ��: " << (v->getLicensePlate() ? v->getLicensePlate() : "�� ���.") << std::endl;
            v->setLicensePlate("GENERIC1");
            std::cout << "����� �������� ���� ��: " << (v->getLicensePlate() ? v->getLicensePlate() : "�� ���.") << " (������ ���� GENERIC1)\n";
        }


        UnattendedBag* ub = dynamic_cast<UnattendedBag*>(myDetectedObject);
        if (ub) {
            std::cout << "\n--- ����������� ������ ��� ��������� ����� ---\n";
            std::cout << "����� ����������� ��������� �����: " << ub->getDetectedTimeSeconds() << std::endl;
            ub->setDetectedTimeSeconds(3600); // 1 ��� ����� ��������
            std::cout << "����� ����� ����������� ��������� �����: " << ub->getDetectedTimeSeconds() << " (������ ���� 3600)\n";
            ub->setDetectedTimeSeconds(90000); // ������� ���������� ���������� �����
            std::cout << "����� ����������� ����� ������� ���������� ����������: " << ub->getDetectedTimeSeconds() << " (������ ���� 3600)\n";
        }

        std::cout << "\n--- ������ ����� ��������� ����� set ������ ---\n";
        std::cout << *myDetectedObject << std::endl;
    }
    std::cout << "---------------------------------\n";

    delete myDetectedObject;
    myDetectedObject = nullptr;

    std::cout << "\n��������� ���������.\n";

    return 0;
}