#pragma once
#include <math.h>
#include <iostream>
#include <algorithm>
#include "Problem.h"

#define T_ZERO 10000
#define T_END 1000
#define ALFA 0.95

#define P_SWAP 40
#define P_INSERT 20
#define P_REVERS 10
#define P_ADSWAP 30

#define P_RIGHT 70

using namespace std;

class SA_Algotythm
{
	Problem problem;

	vector<City> move(vector<City> v, size_t oldIndex, size_t newIndex);
	vector<City> swapV(vector<City> v, size_t oldIndex, size_t newIndex);
	vector<City> revers(vector<City> v);
	vector<City> adjacentSwap(vector<City> v, size_t oldIndex, size_t newIndex);

    public:
        SA_Algotythm();
        ~SA_Algotythm();
        Problem SaAlg(Problem newProblem);
};
