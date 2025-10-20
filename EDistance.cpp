// Copyright 2024 by Juan Fernando Ruiz

#include <iostream>
#include <algorithm>
#include "EDistance.hpp"

EDistance::EDistance(const std::string x, const std::string y) {
    this->x = x;
    this->y = y;
    M = x.size();
    N = y.size();
    opt.resize(M + 1, std::vector<int>(N + 1, 0));
}

int EDistance::penalty(char a, char b) {
    if (a == '-' || b == '-') {
        return 2;
    }

    return (a == b) ? 0 : 1;
}

int EDistance::min3(int a, int b, int c) {
    return std::min(a, std::min(b, c));
}

int EDistance::optDistance() {
    for (int i = M; i >= 0; --i) {
        for (int j = N; j >= 0; --j) {
            if (i == M) {
                opt[i][j] = 2 * (N - j);
            } else if (j == N) {
                opt[i][j] = 2 * (M - i);
            } else {
                opt[i][j] = min3(
                    opt[i + 1][j + 1] + penalty(x[i], y[j]),
                    opt[i + 1][j] + 2,
                    opt[i][j + 1] + 2);
            }
        }
    }
    return opt[0][0];
}

std::string EDistance::alignment() {
    std::string alignmentStr;
    int i = 0;
    int j = 0;
    while (i < M || j < N) {
        if (i < M && j < N && (opt[i][j] == opt[i + 1][j + 1] +
        penalty(x[i], y[j]))) {
            alignmentStr += x[i];
            alignmentStr += " ";
            alignmentStr += y[j];
            alignmentStr += " ";
            alignmentStr += std::to_string(penalty(x[i], y[j]));
            alignmentStr += "\n";
            i++;
            j++;
        } else if (i < M && opt[i][j] == (opt[i + 1][j] + 2)) {
            alignmentStr += x[i];
            alignmentStr += " - ";
            alignmentStr += std::to_string(penalty(x[i], '-'));
            alignmentStr += "\n";
            ++i;
        } else {
            alignmentStr += "- ";
            alignmentStr += y[j];
            alignmentStr += " ";
            alignmentStr += std::to_string(penalty('-', y[j]));
            alignmentStr += "\n";
            j++;
        }
    }
    return alignmentStr;;
}
