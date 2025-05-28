#include "Person.h"
#include <iostream> 

// Ðåàëèçàöèÿ ìåòîäîâ Person
Person::Person() : DetectedObject(), gender(2), childStatus(2), glassesStatus(2), beardStatus(2) {}
Person::Person(int x1, int y1, int x2, int y2,
    int g, int c, int gl, int b)
    : DetectedObject(x1, y1, x2, y2) {
    setGender(g);
    setChildStatus(c);
    setGlassesStatus(gl);
    setBeardStatus(b);
}
void Person::print(std::ostream& os) const {
    os << "--- ×åëîâåê ---\n";
    DetectedObject::print(os);
    os << "  Ïîë (0=Ìóæ, 1=Æåí, 2=Íå îïð.): " << gender << "\n";
    os << "  Ðåá¸íîê (0=Äà, 1=Íåò, 2=Íå îïð.): " << childStatus << "\n";
    os << "  Î÷êè (0=Åñòü, 1=Íåò, 2=Íå îïð.): " << glassesStatus << "\n";
    os << "  Áîðîäà (0=Åñòü, 1=Íåò, 2=Íå îïð.): " << beardStatus << "\n";
}

void Person::inputInfo() {
    std::cout << "--- Ââîä äàííûõ ×åëîâåêà ---\n";
    DetectedObject::inputInfo();

    std::cout << "  Ââåäèòå ïîë (0=Ìóæ, 1=Æåí, 2=Íå îïð.): ";
    int tempGender;
    while (!(std::cin >> tempGender) || tempGender < 0 || tempGender > 2) {
        std::cout << "Îøèáêà: Ââåäèòå ÷èñëî îò 0 äî 2 äëÿ ïîëà: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    setGender(tempGender);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "  Ââåäèòå ñòàòóñ ðåá¸íêà (0=Äà, 1=Íåò, 2=Íå îïð.): ";
    int tempChildStatus;
    while (!(std::cin >> tempChildStatus) || tempChildStatus < 0 || tempChildStatus > 2) {
        std::cout << "Îøèáêà: Ââåäèòå ÷èñëî îò 0 äî 2 äëÿ ñòàòóñà ðåá¸íêà: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    setChildStatus(tempChildStatus);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "  Ââåäèòå ñòàòóñ î÷êîâ (0=Åñòü, 1=Íåò, 2=Íå îïð.): ";
    int tempGlassesStatus;
    while (!(std::cin >> tempGlassesStatus) || tempGlassesStatus < 0 || tempGlassesStatus > 2) {
        std::cout << "Îøèáêà: Ââåäèòå ÷èñëî îò 0 äî 2 äëÿ ñòàòóñà î÷êîâ: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    setGlassesStatus(tempGlassesStatus);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "  Ââåäèòå ñòàòóñ áîðîäû (0=Åñòü, 1=Íåò, 2=Íå îïð.): ";
    int tempBeardStatus;
    while (!(std::cin >> tempBeardStatus) || tempBeardStatus < 0 || tempBeardStatus > 2) {
        std::cout << "Îøèáêà: Ââåäèòå ÷èñëî îò 0 äî 2 äëÿ ñòàòóñà áîðîäû: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    setBeardStatus(tempBeardStatus);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Person::setGender(int g) {
    if (g >= 0 && g <= 2) {
        gender = g;
    }
    else {
        std::cerr << "Íåâåðíîå çíà÷åíèå äëÿ ïîëà (" << g << "). Äîïóñòèìî (0, 1, 2). Çíà÷åíèå íå èçìåíåíî.\n";
    }
}
int Person::getGender() const { return gender; }

void Person::setChildStatus(int c) {
    if (c >= 0 && c <= 2) {
        childStatus = c;
    }
    else {
        std::cerr << "Íåâåðíîå çíà÷åíèå äëÿ ñòàòóñà ðåáåíêà (" << c << "). Äîïóñòèìî (0, 1, 2). Çíà÷åíèå íå èçìåíåíî.\n";
    }
}
int Person::getChildStatus() const { return childStatus; }

void Person::setGlassesStatus(int gl) {
    if (gl >= 0 && gl <= 2) {
        glassesStatus = gl;
    }
    else {
        std::cerr << "Íåâåðíîå çíà÷åíèå äëÿ ñòàòóñà î÷êîâ (" << gl << "). Äîïóñòèìî (0, 1, 2). Çíà÷åíèå íå èçìåíåíî.\n";
    }
}
int Person::getGlassesStatus() const { return glassesStatus; }

void Person::setBeardStatus(int b) {
    if (b >= 0 && b <= 2) {
        beardStatus = b;
    }
    else {
        std::cerr << "Íåâåðíîå çíà÷åíèå äëÿ ñòàòóñà áîðîäû (" << b << "). Äîïóñòèìî (0, 1, 2). Çíà÷åíèå íå èçìåíåíî.\n";
    }
}
int Person::getBeardStatus() const { return beardStatus; }
