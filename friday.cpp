// 2014.12.01_beads.cpp : Defines the entry point for the console application.
//
/*
ID: zwang1
PROG: friday
LANG: C++11
*/
#include "fstream"
using namespace std;
ofstream fout("friday.out");
ifstream fin("friday.in");

int year, days[7], months[12] = {31,28,31,30,31,30,31,31,30,31,30,31},cursorYear=0,cursorDay=0;

int main()
{
	fin >> year;
	while (year > cursorYear)
	{
		for(int i = 0; i < 12; i++)
		{
			days[cursorDay % 7]++;
			cursorDay += months[i];
			if (i == 1 && ((cursorYear + 1900) % 4 == 0 && ((cursorYear + 1900) % 100 != 0 || (cursorYear + 1900)%400==0)))
			{
				cursorDay++;
			}
		}
		cursorYear++;
	}
	for (int i = 0; i < 6; i++)
	{
		fout << days[i]<<" ";
	}
	fout << days[6]<<endl;
	return 0;
}