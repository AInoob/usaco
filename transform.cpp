// 2014.12.01_beads.cpp : Defines the entry point for the console application.
//
/*
ID: zwang1
PROG: transform
LANG: C++11
*/
#include <fstream>
using namespace std;
ofstream fout("transform.out");
ifstream fin("transform.in");

char map1[10][10], map2[10][10], mapTemp[10][10], mapCopy[10][10];
int n;

bool compare(char a[10][10], char b[10][10])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] != b[i][j])
				return false;
		}
	}
	return true;
}

void getMap(char map[10][10])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fin >> map[i][j];
		}
	}
}

void rotate90(char a[10][10], char b[10][10])
{
	for (int i = 0; i < n*n; i++)
	{
		mapCopy[i%n][n - 1 - i / n] = a[i / n][i % n];
	}
	for (int i = 0; i < n*n; i++)
	{
		b[i / n][i % n] = mapCopy[i / n][i % n];
	}
}

void reflect(char a[10][10], char b[10][10])
{
	for (int i = 0; i < n*n; i++)
	{
		mapCopy[i / n][n - 1 - i % n] = a[i / n][i % n];
	}
	for (int i = 0; i < n*n; i++)
	{
		b[i / n][i % n] = mapCopy[i / n][i % n];
	}
}

int main()
{
	fin >> n;
	getMap(map1);
	getMap(map2);
	rotate90(map1, mapTemp);
	if (compare(mapTemp, map2))
	{
		fout << 1 << endl;
		return 0;
	}
	rotate90(mapTemp, mapTemp);
	if (compare(mapTemp, map2))
	{
		fout << 2 << endl;
		return 0;
	}
	rotate90(mapTemp, mapTemp);
	if (compare(mapTemp, map2))
	{
		fout << 3 << endl;
		return 0;
	}
	reflect(map1, mapTemp);
	if (compare(mapTemp, map2))
	{
		fout << 4 << endl;
		return 0;
	}
	for (int i = 0; i < 3; i++)
	{
		rotate90(mapTemp, mapTemp);
		if (compare(mapTemp, map2))
		{
			fout << 5 << endl;
			return 0;
		}
	}
	
	if (compare(map1, map2))
	{
		fout << 6 << endl;
		return 0;
	}
	fout << 7 << endl;
	return 0;
}