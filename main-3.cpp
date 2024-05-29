#include <iostream>
#include "Game.h"
#include "Ship.h"
#include "Mine.h"
#include "Utils.h"

int main() {
    Game game;
    game.initGame(3, 2, 10, 10);
    
    game.gameLoop(10, 2.0);
    
    return 0;
}
