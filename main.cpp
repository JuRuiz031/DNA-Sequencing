// Copyright 2024 by Juan Fernando Ruiz

#include <iostream>
#include <fstream>
#include <string>
#include <SFML/System.hpp>
#include "EDistance.hpp"

using std::cin;
using std::string;

int main() {
    sf::Clock clock;
    std::string left;
    std::string right;

    std::cin >> left;
    std::cin >> right;

    EDistance ed(left, right);

    std::cout << "Edit distance: " << ed.optDistance() << std::endl;


    sf::Time t = clock.getElapsedTime();

    std::cout << ed.alignment();

    std::cout << "Execution time is " << t.asSeconds()
    << "seconds" << std::endl;

    return ed.optDistance();
}
