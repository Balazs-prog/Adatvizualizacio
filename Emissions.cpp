#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
typedef struct EVSZAM 
{
	double atlag=0;
	int db=0;
}EVSZAM;
using namespace std;
int main() {
	ifstream fin("Emissions_Agriculture_Agriculture_total_E_All_Data_(Normalized).csv");
	string line, szemet;
	EVSZAM vilag[2056];
	EVSZAM romania[2056];
	string teszt = "gigagrams";
	double atlag=0;
	int db = 0;
	int evszam = 0;
	getline(fin, line);
		while (getline(fin, line, ','))
		{
			if (line.find("Emissions") != string::npos)
			{
				getline(fin, line, ',');
				istringstream iss(line);
				iss >> szemet;
				szemet.erase(szemet.begin());
				szemet.erase(szemet.end());
				evszam = stoi(szemet);
			}
			if (line.find(teszt) != string::npos)
			{
				getline(fin, line, ',');
				istringstream iss(line);
				iss >> szemet;
				szemet.erase(szemet.begin());
				szemet.erase(szemet.end());
				vilag[evszam].atlag += stod(szemet);
				vilag[evszam].db++;
				continue; 
			}
		};
		//cout << atlag / db << endl;
		fin.close();
		fin.open("Emissions_Agriculture_Agriculture_total_E_All_Data_(Normalized).csv");
		string orszag = "Romania";
		atlag = 0;
		db = 0;
		getline(fin, line);
		while (getline(fin, line, ','))
		{
			if (line.find(orszag) != string::npos)
			{
				while (getline(fin, line, ','))
				{
					if (line.find("Emissions") != string::npos)
					{
						getline(fin, line, ',');
						istringstream iss(line);
						iss >> szemet;
						szemet.erase(szemet.begin());
						szemet.erase(szemet.end());
						evszam = stoi(szemet);
					}
					if (line.find(teszt) != string::npos)
					{
						getline(fin, line, ',');
						istringstream iss(line);
						iss >> szemet;
						szemet.erase(szemet.begin());
						szemet.erase(szemet.end());
						romania[evszam].atlag += stod(szemet);
						romania[evszam].db++;
						break;
					}
				}
			}
		};
		//cout << atlag / db;
		cout << "VILAG:";
		for (int i = 1900; i < 2020; i++) 
		{
			if (vilag[i].db != 0)cout << i << ":"<<vilag[i].atlag / vilag[i].db << endl;
		}
		cout << "ROMANIA";
		for (int i = 1900; i < 2020; i++)
		{
			if (romania[i].db != 0)cout << i << ":" << romania[i].atlag / romania[i].db << endl;
		}
		ofstream fout("EmissionsWorld.txt");
		ofstream fout2("EmissionsRomania.txt");
		for (int i = 1974; i < 2020; i++)
		{
			if (vilag[i].db != 0)fout << i << " " << vilag[i].atlag / vilag[i].db << endl;
		}
		for (int i = 1974; i < 2020; i++)
		{
			if (romania[i].db != 0)fout2 << i << " " << romania[i].atlag / romania[i].db << endl;
		}
		return 0;
}
