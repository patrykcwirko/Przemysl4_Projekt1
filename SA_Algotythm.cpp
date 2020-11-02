#include "SA_Algotythm.h"


SA_Algotythm::SA_Algotythm()
{
	//nic nie robi
}

SA_Algotythm::~SA_Algotythm()
{
	//nic nie robi
}

Problem SA_Algotythm::SaAlg(Problem newProblem)
{
	Problem BeterProblem = newProblem;
	problem = newProblem;
	int t = T_ZERO, te = T_END;
	int i, j, p, son;
	double r, alfa = ALFA;
	bool task = true;

	vector<City> newPerm;
	int L = newProblem.getPerm().size();
	int n = newProblem.getPerm().size();

	while (t > te )
	{
		for (int k = 0; k < L; k++)
		{
			i = rand() % n;
			j = rand() % n;
			p = rand() % 100;
			son = rand() % 100;

			//cout << "  p  " << p << endl;
			if (p <= P_SWAP && task)
			{
				//cout << "swap" << endl;
				problem.setPerm(swapV(newProblem.getPerm(), i, j)); // swap
				task = false;
			}
			if (p <= (P_SWAP + P_INSERT) && task)
			{
				//cout << "insert" << endl;
				problem.setPerm(move(newProblem.getPerm(), i, j)); //insert
				task = false;
			}
			if (p <= (P_SWAP + P_INSERT + P_REVERS) && task)
			{
				//cout << "reverse" << endl;
				problem.setPerm(revers(problem.getPerm())); //reverse
				task = false;
			}
			if (p <= (P_SWAP + P_INSERT + P_REVERS + P_ADSWAP) && task)
			{
				if (son < P_RIGHT && i < problem.getPerm().size() - 1 )
				{
					//cout << "asjecnt swap right" << endl;
					problem.setPerm(swapV(newProblem.getPerm(), i, i + 1)); // asjecnt swap
				}
				else
				{
					//cout << "asjecnt swap left" << endl;
					if (i >= 1)
						problem.setPerm(swapV(newProblem.getPerm(), i, i - 1)); // asjecnt swap
					else
						problem.setPerm(swapV(newProblem.getPerm(), i, i + 1)); // asjecnt swap
					
				}
				task = false;
			}
			task = true;


			if ( newProblem.TraceKm() > problem.TraceKm() ) 
			{
				r = ((double)rand() / (RAND_MAX)) + 1;
				if (r >= exp( (problem.TraceKm() - newProblem.TraceKm()) / t) )
				{
					newProblem = problem;
				}
			}
			problem = newProblem;
			//problem.printShortTrace();
			if (problem.TraceKm() < BeterProblem.TraceKm())
			{
				BeterProblem = problem;
			}
		}
		t = t * alfa;
	}
	return BeterProblem;
}

vector<City> SA_Algotythm::move(vector<City> v, size_t oldIndex, size_t newIndex)
{

	//{ // debug text
	//    cout << "move " << oldIndex << " to " << newIndex << ":";
	//    for (size_t i = 0; i < v.size(); ++i)
	//    {
	//        int n = v[i].id;
	//        if (i == oldIndex)
	//            cout << " [" << n << "] ";
	//        else
	//            cout << "  " << n << "  ";
	//    }
	//    cout << '\n';
	//}

	if (oldIndex > newIndex)
		rotate(v.rend() - oldIndex - 1, v.rend() - oldIndex, v.rend() - newIndex);
	else
		rotate(v.begin() + oldIndex, v.begin() + oldIndex + 1, v.begin() + newIndex + 1);

	//{ // debug text
	//    cout << "     result:";
	//    for (size_t i = 0; i < v.size(); ++i)
	//    {
	//        int n = v[i].id;
	//        if (i == newIndex)
	//            cout << " [" << n << "] ";
	//        else
	//            cout << "  " << n << "  ";
	//    }
	//    cout << '\n';
	//    cout << '\n';
	//}

	return v;
}

vector<City> SA_Algotythm::swapV(vector<City> v, size_t oldIndex, size_t newIndex)
{
	City tmp = v[oldIndex];
	v[oldIndex] = v[newIndex];
	v[newIndex] = tmp;
	return v;
}


vector<City> SA_Algotythm::revers(vector<City> v)
{
	int first = 0;
	int last = v.size() - 1;
	City tmp = v[first];
	while ((first != last) && (first != --last))
	{
		tmp = v[first];
		v[first] = v[last];
		v[last] = tmp;
		++first;
	}
	return v;
}

vector<City> SA_Algotythm::adjacentSwap(vector<City> v, size_t oldIndex, size_t newIndex)
{
	City tmp = v[oldIndex];
	v[oldIndex] = v[newIndex];
	v[newIndex] = tmp;
	return v;
}
