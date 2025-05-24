#pragma once
#include "Entity.h"
#include <iostream>

class UnattendedBag : public Entity {
    int timeSeen;
public:
    UnattendedBag(int x1, int y1, int x2, int y2, int time);

    // Getter
    int getTimeSeen() const;

    // Setter
    void setTimeSeen(int time); // ћожно добавить валидацию времени, если нужно

    std::ostream& Print(std::ostream& os) const override;
};