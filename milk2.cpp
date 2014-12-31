// 2014.12.01_beads.cpp : Defines the entry point for the console application.
//
/*
ID: zwang1
PROG: milk2
LANG: C++11
*/

#include <fstream>
using namespace std;
ofstream fout("milk2.out");
ifstream fin("milk2.in");

bool data[1000000];
int n,a,b,s=1000000,e=0,work=0,relax=0,maxWork=0,maxRelax=0;

int main()
{
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> a >> b;
		s = s > a ? a : s;
		e = e < b ? b : e;
		for (int j = a; j < b; j++)
		{
			data[j] = true;
		}
	}
	for (int i = s; i <= e; i++)
	{
		if (!data[i])
		{
			relax++;
			maxWork = maxWork < work ? work : maxWork;
			work = 0;
		}
		else
		{
			maxRelax = maxRelax < relax ? relax : maxRelax;
			relax = 0;
			work++;
		}
	}
	fout << maxWork << " " << maxRelax<<endl;
	return 0;
}

