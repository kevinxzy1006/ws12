#ifndef GAME_H
#define GAME_H

#include <vector>
#include "GameEntity.h"
#include "Ship.h"
#include "Mine.h"
#include "Utils.h"

class Game {
    private:
    std::vector<GameEntity*> entities;

    public:
    //Constructor and destructor
    Game();
    ~Game();

    //Getter
    std::vector<GameEntity*>& get_entities() {
        return entities;
    }
    void set_entities(std::vector<GameEntity*>& entities) {
        this->entities = entities;
    }
    
    std::vector<GameEntity*> initGame(int numShips, int numMines, int gridWidth, int gridHeight) {
        entities.clear; //clear all the previous entities

        // Create Ships and Mines with random positions
        for (int i=0; i<numShips; i++) {
            int x = Utils::generateRandomPos(gridWidth);
            int y = Utils::generateRandomPos(gridHeight);
            entities.push_back(new Ship(x,y));
        }
        for (int i = 0; i < numMines; i++) {
            int x = Utils::generateRandomPos(gridWidth);
            int y = Utils::generateRandomPos(gridHeight);
            entities.push_back(new Mine(x, y));
        }

        return entities;
    }

    void gameLoop(int maxIterations, double mineDistanceThreshold) {
        int iterations = 0;
        while(iterations < maxIterations) {
            //Move all ship objects
            for (std::vector<GameEntity*>::iterator it = entities.begin(); it != entities.end(); it++) {
                Ship* ship = dynamic_cast<Ship*>(entities[i]);
                if (ship) {
                    ship->move(1, 0);
            }

            // Check for Ship proximity to Mines and explode if necessary
            for (std::vector<GameEntity*>::iterator shipIt = entities.begin(); shipIt != entities.end(); shipIt++) {
                Ship* ship = dynamic_cast<Ship*>(*shipIt);
                if (ship) {
                    for (std::vector<GameEntity*>::iterator mineIt = entities.begin(); mineIt != entities.end(); mineIt++) {
                        Mine* mine = dynamic_cast<Mine*>(*mineIt);
                        if (mine->get_type() == 'M') {
                            double distance = Utils::calculateDistance(ship->get_x(), ship->get_y(), mine->get_x(), mine->get_y());
                            if (distance < mineDistanceThreshold) {
                                Explosion explosion = mine->explode();
                                explosion.apply(*ship);
                            }
                        }
                    }
                }
            }
            // Check termination condition
            bool allShipsDestroyed = true;
            for (std::vector<GameEntity*>::iterator it = entities.begin(); it != entities.end(); ++it) {
                Ship* ship = dynamic_cast<Ship*>(*it);
                if (ship) {
                    allShipsDestroyed = false;
                    break;
                }
            }
            if (allShipsDestroyed) {
                std::cout << "All ships destroyed!" << std::endl;
                break;
            }

        ++iteration;
        }
    }
}
};

#endif //GAME_H