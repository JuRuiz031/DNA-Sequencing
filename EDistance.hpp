// Copyright 2024 by Juan Fernando Ruiz

#ifndef EDISTANCE_HPP
#define EDISTANCE_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Vector2.hpp>

class EDistance {
 public:
    EDistance(const std::string x, const std::string y);
    int optDistance();
    std::string alignment();
    static int penalty(char a, char b);
    static int min3(int a, int b, int c);

 private:
    std::string x;
    std::string y;
    int M;
    int N;
    std::vector<std::vector<int>> opt;
};
#endif  // EDISTANCE_HPP
