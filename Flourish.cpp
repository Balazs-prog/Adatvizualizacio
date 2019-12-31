#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef struct Adat
{
	double longi = 0, lati = 0, atlag[35] = { 0 };
	string nev;
}Adat;

int main()
{
	ifstream fin("kivonva_az_atlagbol.csv");
	ofstream fout("kivonva_az_atlagbol_rendes.txt");
	string line;
	Adat varosok[100];
	vector<int>evek;
	getline(fin, line, ','); getline(fin, line, ','); getline(fin, line, ',');
	int evszam = 1;
	while (evszam != 2018)
	{
		getline(fin, line, ',');
		istringstream iss(line);
		iss >> evszam;
		evek.push_back(evszam);
	}
	getline(fin, line);
	evek.push_back(2019);
	int i = 0;
	string longi, lati, atlag;
	while (getline(fin, longi, ','))
	{
		varosok[i].longi = stod(longi);
		getline(fin, lati, ',');
		varosok[i].lati = stod(lati);
		getline(fin, line, ',');
		for (int j = 0; j < 34; j++)
		{
			getline(fin, atlag, ',');
			varosok[i].atlag[j] = stod(atlag);
		}
		getline(fin, atlag);
		varosok[i].atlag[34] = stod(atlag);
		i++;
	}
	for (i = 0; i < 35; i++)
	{
		for (auto a : varosok)
		{
			if(a.lati!=0)cout << a.lati << " " << a.longi << " " << a.atlag[i] << " " << evek[i] << endl;
		}
	}
}
