#pragma once
#include <vector>
#include <iostream>
#include <concepts>

template<typename T>
void PrintVec(std::vector<T>& vec)
{
    for(auto &t : vec) {
        std::cout << t << " ";
    }
    std::cout << std::endl;
}
