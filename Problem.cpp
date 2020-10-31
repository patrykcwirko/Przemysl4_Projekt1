#include "Problem.h"
#include <iostream>

Problem::Problem(string file, int cent_mag)
{

    ifstream  data( file );
    int licznik = 0;
    string line, smietnik;
    City tmp_car;
    string delimiter = ";";
    size_t start, end;
    string token;

    if (!data.eof() )
    {
        getline(data, line, '\n');
        end = line.find(delimiter);
        token = line.substr(0, end);
        city_count = atoi(token.c_str());

        getline(data, line, '\n');
        end = line.find(delimiter);
        token = line.substr(0, end);
        cout << token << endl;
        unit = token;

        int i = 0;
        for (; i < city_count; i++)
        {
            getline(data, line, '\n');
            start = 0U;
            end = line.find(delimiter);
            tab.push_back(vector<double>());
            for (int j = 0; j < city_count; j++)
            {
                token = line.substr(start, end - start);
                tab[i].push_back(atoi(token.c_str()));
                start = end + delimiter.length();
                end = line.find(delimiter, start);
            }
        }
        cout << i << endl;
    }

    int j = 0;
    for (; j < city_count; j++)
    {
        getline(data, line);

        size_t start = 0U, index = 0U;
        size_t end = line.find(delimiter);
        string token;
        while (end != string::npos)
        {
            token = line.substr(start, end - start);
            switch (index)
            {
                case 0:
                    tmp_car.id = j;
                    break;
                case 1:
                    tmp_car.code = token;
                    break;
                case 2:
                    tmp_car.name = token;
                    break;
                case 3:
                    tmp_car.lat = atoi(token.c_str());
                    break;
                case 4:
                    tmp_car.lng = atoi(token.c_str());
                    break;
            }
            index++;
            start = end + delimiter.length();
            end = line.find(delimiter, start);
        }
        citis.push_back(tmp_car);
        if (j == cent_mag)
        {
            centMag = tmp_car;
        }
    }
    cout << "." << endl;

}

void Problem::maxTrace()
{
    vector<City> tmp = citis;
    City mag;
    //int newI = 0, newL = 0;
    City newI, newL;
    int tir = 1, tmpLng = 0, tmpIng = 0, taskCount;
    bool limit = true;

    perm.clear();
    cars = 0;
    tmp.erase(tmp.begin() + FindCity(tmp, centMag.id));


    while (tmp.size() != 0 )
    {
        taskCount = 1;
        perm.push_back(centMag);
        limit = true;

        cout << "--------------" << endl;

        tmpIng = 0;
        for (City i : tmp)
        {
            cout << tab[centMag.id][i.id] << " kk " << tmpIng << " lll " << i.id << endl;
            if (tmpIng < tab[centMag.id][i.id]) {
                cout << "fkoakfoa " << tmpIng << "fafaga " << tab[centMag.id][i.id] << endl;
                tmpIng = tab[centMag.id][i.id];
                newI = i;
            }
        }
        /*
        for (int i = 0; i < tmp.size(); i++)
        {
            cout << tab.size() << endl;
            cout << "tt " << centMag.id << "kk " << i << endl;
            if (tmpLng < tab[centMag.id][tmp[i].id]) {
                cout << "fkoakfoa " << tmpLng << "fafaga " << tab[centMag.id][tmp[i].id] << endl;
                tmpLng = tab[centMag.id][tmp[i].id];
                newI = i;
            }
        }*/
        cout << "_-_-_-_-_-_-_--_III " << newI.id  << endl;
        perm.push_back(newI);
        //FindCity(newI.id);
        tmp.erase(tmp.begin() + FindCity(tmp, newI.id));
        
        cout << "test remove" << endl;    

        taskCount = 1;
        while (limit && tmp.size() != 0)
        {
            cout << "--------------" << tmp.size() << endl;
            tmpLng = MAX_SEARCH_VALUE;
            for (City j : tmp)
            {
                cout << tab[newI.id][j.id] << " fafa " << j.id << endl;
                if (tmpLng > tab[newI.id][j.id]) {
                    tmpLng = tab[newI.id][j.id];
                    newL = j;
                }
            }
            if (taskCount + 1 <= JOB_LIMIT)
            {
                cout << "--------------LLL" << newL.id << endl;
                perm.push_back(newL);
                tmp.erase(tmp.begin() + FindCity(tmp, newL.id));
                taskCount++;
            }
            else
            {
                limit = false;
            }
        }
        cars++;
    }

}

void Problem::printTrace()
{
    for ( City i : perm)
    {
        if (i.id == centMag.id)
        {
            cout << endl;
        }
        cout << i.id << "->";
    }
}

int Problem::TraceKm()
{
    int traceKm = 0;

    for (int i = 1; i < perm.size() - 1; i++)
    {
            traceKm += tab[perm[i - 1].id][perm[i].id];
    }
    return traceKm;
}

int Problem::FindCity(vector<City> tmp, int ider)
{
    for (size_t i = 0; i < tmp.size(); ++i) {
        if (tmp[i].id == ider)
            return i;
    }
}
