#include <iostream>
#include <tuple>
#include <cstdlib>
#include <ctime>
#include "GameEntity.h"
#include "Effect.h"
#include "Utils.h"

int main() {
    std::srand(time(0)); // Seed the random number generator

    int gridWidth = 100;
    int gridHeight = 100;

    // Generate some random positions
    std::tuple<int, int> pos1 = Utils::generateRandomPos(gridWidth, gridHeight);
    std::tuple<int, int> pos2 = Utils::generateRandomPos(gridWidth, gridHeight);

    std::cout << "Position 1: " << pos1 <<  std::endl;
    std::cout << "Position 2: " << pos2 <<  std::endl;

    // Calculate the distance between these positions
    double distance = Utils::calculateDistance(pos1, pos2);
    std::cout << "Distance between positions: " << distance << std::endl;

    return 0;
}
