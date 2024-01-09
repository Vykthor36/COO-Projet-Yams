#include "lancer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

std::vector<int> lancer::lancerDés()
{
    srand(time(0));
    std::vector<int> L;
    for (int i = 0; i < 5; i++) L.push_back(rand() % 6 + 1);

    return L;
}