#define _CRT_SECURE_NO_WARNINGS
#include "Human.h"
#include <cstring>
#include <stdexcept>

// ��������������� ������� ��� ����������� ������������ C-����� � �������������� new/delete[]
// ��������� _strdup/strdup ������ ���������� malloc/free.
static char* safe_strdup_cpp(const char* str) {
    if (!str) return nullptr;
    size_t len = strlen(str) + 1;
    char* new_str = new char[len];
    // new char[] ������� std::bad_alloc � ������ �������, ��� ����� ����������� ����,
    // ��� ����� ��������� if (!new_str) � ������� ���� ����������.
    // ��� ��������, ���������� �� std::bad_alloc.
    strcpy(new_str, str);
    return new_str;
}

Human::Human(const char* g, const char* child, const char* glasses, const char* beard,
    int x1, int y1, int x2, int y2)
    : Entity(x1, y1, x2, y2) {
    // ������������� ����� nullptr, ����� ������� ��������� ��������
    gender = nullptr;
    isChild = nullptr;
    hasGlasses = nullptr;
    hasBeard = nullptr;

    setGender(g);
    setIsChild(child);
    setHasGlasses(glasses);
    setHasBeard(beard);
}

Human::Human(const Human& other) : Entity(other) { // ���������� ����������� ����������� �������� ������
    gender = safe_strdup_cpp(other.gender);
    isChild = safe_strdup_cpp(other.isChild);
    hasGlasses = safe_strdup_cpp(other.hasGlasses);
    hasBeard = safe_strdup_cpp(other.hasBeard);
}

Human& Human::operator=(const Human& other) {
    if (this != &other) {
        Entity::operator=(other); // ������������ ������� �����

        // ���������� ������� ��� ���������� ������� � �����������
        setGender(other.gender);
        setIsChild(other.isChild);
        setHasGlasses(other.hasGlasses);
        setHasBeard(other.hasBeard);
    }
    return *this;
}

Human::~Human() {
    delete[] gender;
    delete[] isChild;
    delete[] hasGlasses;
    delete[] hasBeard;
}

// Getters
const char* Human::getGender() const { return gender; }
const char* Human::getIsChild() const { return isChild; }
const char* Human::getHasGlasses() const { return hasGlasses; }
const char* Human::getHasBeard() const { return hasBeard; }

// Setters
void Human::setGender(const char* g) {
    delete[] gender;
    gender = safe_strdup_cpp(g);
}

void Human::setIsChild(const char* child) {
    delete[] isChild;
    isChild = safe_strdup_cpp(child);
}

void Human::setHasGlasses(const char* glasses) {
    delete[] hasGlasses;
    hasGlasses = safe_strdup_cpp(glasses);
}

void Human::setHasBeard(const char* beard) {
    delete[] hasBeard;
    hasBeard = safe_strdup_cpp(beard);
}