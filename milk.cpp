/*
ID: zwang1
PROG: milk
LANG: C++11
*/
#include <fstream>
using namespace std;
ofstream fout("milk.out");
ifstream fin("milk.in");

int map[1001], n, m, p, a, c = 0, cursor = 0, price = 0,temp;

int main()
{
	fin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		fin >> p >> a;
		for (int j = 0; j < a; ++j)
		{
			map[p]++;
		}
	}
	while (c < n)
	{
		if (map[cursor] > 0)
		{
			temp = (map[cursor] < n - c ? map[cursor] : n - c);
			c += temp;
			price += cursor * temp;
			map[cursor]==0;
		}
		cursor++;
	}
	fout << price << endl;
	return 0;
}