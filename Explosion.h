#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "GameEntity.h"
#include "Effect.h"

class Explosion : public GameEntity, public Effect {
    protected:
    int x,y;
    char type;

    public:
    Explosion(int x, int y, char type) : GameEntity(x, y, 'E') {}

    GameEntity::virtual void apply(GameEntity& entity) {
        entity.set_position(-1,-1);
        entity.set_type('X');
    }
};
#endif //EXPLOSION_H