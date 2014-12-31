
/*
ID: zwang1
PROG: namenum
LANG: C++11
*/
#include <fstream>
#include <set>
#include <string>
using namespace std;
ofstream fout("namenum.out");
ifstream fin("namenum.in");
ifstream din("dict.txt");

set<string> dict;
set<string> possibleNames;

char map[8][3] = 
{	{ 'A', 'B', 'C' },
	{ 'D', 'E', 'F' },
	{ 'G', 'H', 'I' },
	{ 'J', 'K', 'L' },
	{ 'M', 'N', 'O' },
	{ 'P', 'R', 'S' },
	{ 'T', 'U', 'V' },
	{ 'W', 'X', 'Y' }, };

void getDict()
{
	string tempString;
	while (din >> tempString)
	{
		dict.insert(tempString);
	}
}

void addPossibleNames(long long a,string s)
{
	if (a != 0)

	{
		addPossibleNames(a / 10, s + map[a % 10 - 2][0]);
		addPossibleNames(a / 10, s + map[a % 10 - 2][1]);
		addPossibleNames(a / 10, s + map[a % 10 - 2][2]);
	}
	else
	{
		if (dict.find(s) != dict.end())
		{
			possibleNames.insert(s);
		}
	}
}

int main()
{
	getDict();
	long long a, tempInt=0;
	fin >> a;
	while (a != 0)
	{
		tempInt *= 10;
		tempInt += a % 10;
		a /= 10;
	}
	bool none = true;
	addPossibleNames(tempInt,"");
	for (set<string>::iterator it = possibleNames.begin(); it != possibleNames.end(); ++it)
	{
		none = false;
		fout << *it << endl;
	}
	if (none)
	{
		fout << "NONE" << endl;
	}
	return 0;
}