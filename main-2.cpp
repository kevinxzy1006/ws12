#include <iostream>

#include "GameEntity.h"
#include "Explosion.h"
#include "Mine.h"
#include "Ship.h"

int main() {
    // Create Ship object and call its functions
    Ship ship(5, 5);
    ship.print(); // Print Ship's initial position and type
    ship.move(1, 1); // Move Ship
    ship.print(); // Print Ship's updated position

    // Create Mine object and call its functions
    Mine mine(10, 10);
    mine.print(); // Print Mine's position and type
    Explosion explosion = mine.explode(); // Explode Mine
    mine.print(); // Print Mine's updated type after explosion

    // Create an Explosion object and call apply() on a Ship object
    Explosion explosion2(3, 3);
    explosion2.apply(ship);
    ship.print(); // Print Ship's position after applying explosion

    return 0;
}