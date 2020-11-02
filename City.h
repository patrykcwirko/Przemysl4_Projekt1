#pragma once
#include <string>
#include <vector>

using namespace std;

struct City
{
	int id;
	long lat;
	long lng;
	string code;
	string name;
	City() { 
		id = 0;
		lat = 0L;
		lng = 0L;
	};
	City(int _id, long _lat, long _lng, string _code, string _name) { 
		id = _id;
		lat = _lat;
		lng = _lng;
		code = _code;
		name = _name;
	};
	City& operator= (const City& s) {
		id = s.id;
		lat = s.lat;
		lng = s.lng;
		code = s.code;
		name = s.name;
		return *this;
	};
	City(const City& s) {
		id = s.id;
		lat = s.lat;
		lng = s.lng;
		code = s.code;
		name = s.name;
	};
}; 
