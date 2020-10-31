#pragma once
#include "City.h"
#include <vector>
#include <fstream>
#include <string>

#define JOB_LIMIT 3

using namespace std;

class Problem
{
	vector<vector<double>> tab;
	string unit;
	int city_count;
	vector<City> citis;
	int cars;
	vector<City> perm;
	City centMag;

	int FindCity(vector<City> tmp, int ider);

	public:
		Problem(string file, int cent_mag);
		vector<vector<double>> getTab() { return tab; }
		string getUnit() { return unit; }
		int getCityCount() { return city_count; }
		vector<City> getCity() { return citis; }
		vector<City> getPerm() { return perm; }
		void maxTrace();
		void printTrace();


};

