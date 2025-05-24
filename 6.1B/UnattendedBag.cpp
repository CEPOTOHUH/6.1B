#include "UnattendedBag.h"

UnattendedBag::UnattendedBag(int x1, int y1, int x2, int y2, int time)
    : Entity(x1, y1, x2, y2) {
    // ћожно добавить валидацию дл€ time, например, time >= 0
    if (time < 0) {
        throw std::invalid_argument("Time seen cannot be negative.");
    }
    timeSeen = time;
}

// Getter
int UnattendedBag::getTimeSeen() const { return timeSeen; }

// Setter
void UnattendedBag::setTimeSeen(int time) {
    // ћожно добавить валидацию дл€ time, например, time >= 0
    if (time < 0) {
        throw std::invalid_argument("Time seen cannot be negative.");
    }
    timeSeen = time;
}

std::ostream& UnattendedBag::Print(std::ostream& os) const {
    os << "[UnattendedBag] Coords: (" << getXmin() << "," << getYmin() << ")-(" << getXmax() << "," << getYmax() << ") ";
    os << "First seen at: " << getTimeSeen() << " seconds since midnight";
    return os;
}