#pragma once
#include "Car.h"
#include <vector>
#include <fstream>
#include <string>

#define CARS_COUNT 6

using namespace std;

class Problem
{
	vector<vector<int>> tab;
	string unit;
	int city_count;
	vector<Car> cars;

	public:
		Problem( string file );
		vector<vector<int>> getTab() { return tab; }
		string geyUnit() { return unit; }
		int getCityCount() { return city_count; }
		vector<Car> getCars() { return cars; }


};

