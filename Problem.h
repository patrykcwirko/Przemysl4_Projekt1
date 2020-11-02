#pragma once
#include "City.h"
#include <vector>
#include <fstream>
#include <string>

#define JOB_LIMIT 12
#define MAX_SEARCH_VALUE 10000000000

using namespace std;

class Problem
{
	int city_count;
	int cars;
	string unit;
	City centMag;
	vector<City> citis;
	vector<City> perm;
	vector<vector<double>> tab;

	int FindCity(vector<City> tmp, int ider);

	public:
		Problem();
		Problem& operator= (const Problem& s);
		Problem(const Problem& problems);
		Problem(string file, int cent_mag);
		vector<vector<double>> getTab() { return tab; }
		string getUnit() { return unit; }
		int getCityCount() { return city_count; }
		vector<City> getCity() { return citis; }
		vector<City> getPerm() { return perm; }
		void setPerm(vector<City> newPerm) { perm = newPerm; }
		void maxTrace();
		void printTrace();
		void printShortTrace();
		int TraceKm();


};

