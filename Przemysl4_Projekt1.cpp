// Przemysl4_Projekt1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <sstream>
#include <string>
#include "Problem.h"
#include "SA_Algotythm.h"

using namespace std;

int main()
{
    int BestCityIndex, BestCityKm = 100000, CityKm = 0;
    Problem problem1( "PL.csv", 10);
    SA_Algotythm algor;
    //problem.maxTrace();
    //problem.printTrace();

    problem1.maxTrace();
    for (size_t i = 0; i < 25; i++)
    {
        Problem problem("PL.csv", i);
        problem.maxTrace();
        CityKm = problem.TraceKm();
        if (CityKm < BestCityKm)
        {
            BestCityKm = CityKm;
            BestCityIndex = i;
        }
        cout << "przejechana trasa dla magacynu centralnego w "<< problem.getCity()[i].code << ": " << CityKm << endl;
    }
    cout << endl << "Najlepiej ustawić magazyn centralny w " << problem1.getCity()[BestCityIndex].code << endl;
    cout << endl << endl;
    problem1 = algor.SaAlg(problem1);
    cout << endl << "najlepsza trana dla " << problem1.getCity()[10].code << " ma długość " << problem1.TraceKm() << endl;

    //std::cout << problem.getTab()[0][24] <<" Hello World!\n";
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
