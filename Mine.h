#ifndef SHIP_H
#define SHIP_H

#include "GameEntity.h"

class Ship : public GameEntity {
    public:
    Mine(int x, int y) : GameEntity(x, y, 'M') {}
    Explosion explode() {
        type = 'X'; // Change Mine type to 'X' after exploding
        return Explosion(x, y);
    }
}