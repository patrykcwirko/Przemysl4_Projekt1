#include "Problem.h"

Problem::Problem(string file)
{

	std::ifstream  data( file );
    int licznik = 0;
    string line, smietnik;
    Car tmp_car;

    if (!data.eof() )
    {
        getline(data, line, ';');
        city_count = atoi(line.c_str());

        getline(data, line, ';');
        unit = line;

        for (int i = 0; i < city_count; i++)
        {
            for (int j = 0; j < city_count; j++)
            {
                getline(data, line, ';');
                tab[i].push_back(atoi(line.c_str()));
            }
        }
    }

    while (!data.eof())
    {

        getline(data, line, ';');
        tmp_car.code = line;
        getline(data, line, ';');
        tmp_car.name = line;
        getline(data, line, ';');
        tmp_car.lat = atoi(line.c_str());
        getline(data, line, ';');
        tmp_car.lng = atoi(line.c_str());
        cars.push_back(tmp_car);

    }

}
