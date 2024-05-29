#ifndef SHIP_H
#define SHIP_H

#include "GameEntity.h"

class Ship : public GameEffect {
    public:
    Ship(int x, int y) : GameEffect(x, y, 'E') {}

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }
};
#endif //SHIP_H