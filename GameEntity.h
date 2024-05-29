#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include <tuple>

class GameEntity {
private:
    std::tuple<int, int> position;
    char type;

public:
    GameEntity(int x, int y, char type) : position(std::make_tuple(x, y)), type('t') {}

    std::tuple<int, int> getPos(){
        return position;
    }

    char getType(){
        return type;
    }
};

#endif // GAME_ENTITY_H
