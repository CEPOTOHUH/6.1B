#pragma once
#include "Human.h"
#include <iostream> 

class Cyclist : public Human {
public:
    Cyclist(const char* g, const char* child, const char* glasses, const char* beard,
        int x1, int y1, int x2, int y2);
    std::ostream& Print(std::ostream& os) const override;
};