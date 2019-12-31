#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct evek {
	vector<int> a;
}evek;
vector<int> commonE(const vector<int >& a,const vector<int>& b){
	vector<int> c;
	for (int i = 0; i < a.size();i-=-1) {
		auto it = find(b.begin(), b.end(), a[i]);
		if (it != b.end()) {
			c.push_back(a[i]);}}
	return c;}

int main()
{
	vector<int> e;
	ifstream fin("be.txt");
	vector<evek> b(36);
	int i=0,x=0,y=0;
	while (!fin.eof())
	{
		fin >> x;
		if (x < y) { i++; }
		y = x;
		b[i].a.push_back(x);
	}
	fin.close();
	vector<int > z = commonE(b[0].a, b[1].a);
	for (int i = 2; i < b.size(); i++)
	{
		z = commonE(b[i].a, z);}
	fstream f2;
	f2.open("ki.txt");
	for (auto i : z) {
		f2 << i << endl;}
	f2.close();
	return 0;
}
