
/*
ID: zwang1
PROG: palsquare
LANG: C++11
*/
#include <fstream>
#include <string>
using namespace std;
ofstream fout("palsquare.out");
ifstream fin("palsquare.in");

char getLetter(int a)
{
	if (a < 10)
	{
		return '0' + a;
	}
	else
	{
		return 'A' + a - 10;
	}
}

string toBase(int a, int base)
{
	string tempString = "";
	while (a != 0)
	{
		int tempInt = a % base;
		tempString = getLetter(tempInt) + tempString;
		a /= base;
	}
	return tempString;
}

bool checkPalSquare(string s)
{
	for (int i = 0; i < (s.length()+1)/2; ++i)
	{
		if (s.at(i) != s.at(s.length() - 1 - i))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int base;
	string tempString;
	fin >> base;
	for (int i = 1; i < 301; ++i)
	{
		tempString = toBase(i*i, base);
		if (checkPalSquare(tempString))
		{
			fout << toBase(i,base) << " " << tempString << endl;
		}
	}
	return 0;
}

