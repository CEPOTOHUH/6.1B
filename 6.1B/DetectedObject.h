#ifndef DETECTED_OBJECT_H
#define DETECTED_OBJECT_H

#include <iostream>
#include <limits> // Для std::numeric_limits

class DetectedObject {
public:
    struct Coordinates {
        int Xmin, Ymin, Xmax, Ymax;

        Coordinates();
        Coordinates(int x1, int y1, int x2, int y2);
    };

protected:
    Coordinates coordinates;

public:
    DetectedObject();
    DetectedObject(int x1, int y1, int x2, int y2);
    virtual ~DetectedObject() = default;

    // Правило Пяти
    DetectedObject(const DetectedObject& other);
    DetectedObject& operator=(const DetectedObject& other);
    DetectedObject(DetectedObject&& other) noexcept;
    DetectedObject& operator=(DetectedObject&& other) noexcept;

    virtual void print(std::ostream& os) const;
    virtual void inputInfo();
};

std::ostream& operator<<(std::ostream& os, const DetectedObject& obj);

#endif // DETECTED_OBJECT_H