#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdexcept>

#include "Person.h"
#include "Cyclist.h"
#include "Car.h"
#include "Motorcycle.h"
#include "UnattendedBag.h"

void clear_cin_buffer() {
    std::cin.clear(); // Очистка флагов ошибок
    std::cin.ignore(10000, '\n'); // Игнорировать до 10000 символов или до новой строки
}

int main() {
    try {
        const int max_input_len = 100;
        char gender_in[max_input_len], child_in[max_input_len], glasses_in[max_input_len], beard_in[max_input_len];
        int x1_in, y1_in, x2_in, y2_in;

        std::cout << "Enter person (gender child glasses beard x1 y1 x2 y2): ";
        if (!(std::cin >> gender_in >> child_in >> glasses_in >> beard_in >> x1_in >> y1_in >> x2_in >> y2_in)) {
            clear_cin_buffer();
            throw std::runtime_error("Invalid input format for person.");
        }
        Person person(gender_in, child_in, glasses_in, beard_in, x1_in, y1_in, x2_in, y2_in);

        std::cout << "Enter cyclist (gender child glasses beard x1 y1 x2 y2): ";
        if (!(std::cin >> gender_in >> child_in >> glasses_in >> beard_in >> x1_in >> y1_in >> x2_in >> y2_in)) {
            clear_cin_buffer();
            throw std::runtime_error("Invalid input format for cyclist.");
        }
        Cyclist cyclist(gender_in, child_in, glasses_in, beard_in, x1_in, y1_in, x2_in, y2_in);

        char number_in[max_input_len], taxi_in[max_input_len];
        int r_in, g_in, b_in;
        std::cout << "Enter car (r g b number taxi x1 y1 x2 y2): ";
        if (!(std::cin >> r_in >> g_in >> b_in >> number_in >> taxi_in >> x1_in >> y1_in >> x2_in >> y2_in)) {
            clear_cin_buffer();
            throw std::runtime_error("Invalid input format for car.");
        }
        Car car(r_in, g_in, b_in, number_in, taxi_in, x1_in, y1_in, x2_in, y2_in);

        std::cout << "Enter motorcycle (r g b number x1 y1 x2 y2): ";
        if (!(std::cin >> r_in >> g_in >> b_in >> number_in >> x1_in >> y1_in >> x2_in >> y2_in)) {
            clear_cin_buffer();
            throw std::runtime_error("Invalid input format for motorcycle.");
        }
        Motorcycle moto(r_in, g_in, b_in, number_in, x1_in, y1_in, x2_in, y2_in);

        int time_in;
        std::cout << "Enter unattended bag (x1 y1 x2 y2 time): ";
        if (!(std::cin >> x1_in >> y1_in >> x2_in >> y2_in >> time_in)) {
            clear_cin_buffer();
            throw std::runtime_error("Invalid input format for unattended bag.");
        }
        UnattendedBag bag(x1_in, y1_in, x2_in, y2_in, time_in);

        std::cout << "\n--- Detected Entities ---\n";
        std::cout << person << "\n" << cyclist << "\n" << car << "\n" << moto << "\n" << bag << "\n";

        std::cout << "\n--- Modifying and Retrieving Person's Gender ---\n";
        std::cout << "Original Gender: " << (person.getGender() ? person.getGender() : "N/A") << std::endl;
        person.setGender("Female_Updated");
        std::cout << "Updated Gender: " << (person.getGender() ? person.getGender() : "N/A") << std::endl;

        std::cout << "\n--- Modifying and Retrieving Car's Color ---\n";
        std::cout << "Original Color (R): " << car.getR() << std::endl;
        try {
            car.setColor(10, 20, 300);
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Error setting color: " << e.what() << std::endl;
        }
        car.setColor(10, 20, 30);
        std::cout << "Updated Color (R): " << car.getR() << std::endl;


    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Input Validation Error: " << e.what() << "\n";
        return 1;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Runtime Error: " << e.what() << "\n";
        return 1;
    }
    catch (const std::bad_alloc& e) { 
        std::cerr << "Memory Allocation Error: " << e.what() << "\n";
        return 1;
    }
    catch (const std::exception& e) {
        std::cerr << "Standard Error: " << e.what() << "\n";
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown error occurred.\n";
        return 1;
    }
    return 0;
}