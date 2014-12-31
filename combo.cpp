/*
ID: zwang1
PROG: combo
LANG: C++11
*/
#include <fstream>
using namespace std;
ofstream fout("combo.out");
ifstream fin("combo.in");

int n, map1[3], map2[3], map3[3], A[100];

int render(int a)
{
	int r = 0;
	for (int i = 0; i < n; ++i)
	{
		A[i] = 0;
	}
	for (int i = -2; i < 3; ++i)
	{
		A[(a + i + n) % n] ++;
	}
	for (int i = 0; i < n; ++i)
	{
		if (A[i] > 0)
		{
			++r;
		}
	}
	return r;
}

int render(int a, int b)
{
	int r=0;
	for (int i = 0; i < n; ++i)
	{
		A[i] = 0;
	}
	for (int i = -2; i < 3; ++i)
	{
		A[(a + i + n) % n] ++;
		A[(b + i + n) % n] += 10;
	}
	for (int i = 0; i < n; ++i)
	{
		if (A[i]%10>0 && A[i]/10>0)
		{
			++r;
		}
	}
	return r;
}

int main()
{
	fin >> n;
	for (int i = 0; i < 3; ++i)
	{
		fin >> map1[i];
	}
	for (int i = 0; i < 3; ++i)
	{
		fin >> map2[i];
		map3[i] = render(map1[i], map2[i]);
		map1[i] = render(map1[i]);
		map2[i] = render(map2[i]);
	}
	fout << map1[0] * map1[1] * map1[2] + map2[0] * map2[1] * map2[2] - map3[0] * map3[1] * map3[2] << endl;
}