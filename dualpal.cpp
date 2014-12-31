
/*
ID: zwang1
PROG: dualpal
LANG: C++11
*/
#include <fstream>
#include <string>
using namespace std;
ofstream fout("dualpal.out");
ifstream fin("dualpal.in");

char getLetter(int a)
{
	return '0' + a;
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
	for (int i = 0; i < (s.length() + 1) / 2; ++i)
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
	int n, a, c = 0,cc;
	string tempString;
	fin >> n >> a;
	for (int i = a + 1; c < n; ++i)
	{
		cc = 0;
		for (int j = 2; j < 11; j++)
		{
			tempString = toBase(i, j);
			if (checkPalSquare(tempString))
			{
				cc++;
				if (cc == 2)
				{
					c++;
					fout << i << endl;
					break;
				}
			}
		}
	}
	return 0;
}