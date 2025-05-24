#pragma once
#include "Entity.h"
#include <cstring>

class Human : public Entity {
protected:
    char* gender;
    char* isChild;
    char* hasGlasses;
    char* hasBeard;
public:
    Human(const char* g, const char* child, const char* glasses, const char* beard,
        int x1, int y1, int x2, int y2);
    Human(const Human& other);
    Human& operator=(const Human& other);
    virtual ~Human();

    // Getters
    const char* getGender() const;
    const char* getIsChild() const;
    const char* getHasGlasses() const;
    const char* getHasBeard() const;

    // Setters
    void setGender(const char* g);
    void setIsChild(const char* child);
    void setHasGlasses(const char* glasses);
    void setHasBeard(const char* beard);
};