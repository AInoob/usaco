/*
ID: zwang1
PROG: barn1
LANG: C++11
*/
#include <fstream>
using namespace std;
ofstream fout("barn1.out");
ifstream fin("barn1.in");

bool map[201];

int m, s, c, temp, minInt=1000, maxInt=0, gap[201], ssum;

int main()
{
	fin >> m >> s >> c;
	for (int i = 0; i < c; i++)
	{
		fin >> temp;
		map[temp] = true;
		minInt = minInt>temp ? temp : minInt;
		maxInt = maxInt < temp ? temp : maxInt;
	}
	temp = 0;
	for (int i = minInt; i <= maxInt; i++)
	{
		if (map[i])
		{
			gap[temp]++;
			temp = 0;
		}
		else
		{
			temp++;
		}
	}
	temp = 0;
	ssum = 0;
	for (int i = s; temp < m - 1 && i != 0; --i)
	{
		if (gap[i] != 0)
		{
			if (gap[i] + temp < m - 1)
			{
				temp += gap[i];
				ssum += gap[i] * i;
			}
			else
			{
				ssum += i * (m - 1 - temp);
				temp = m - 1;
			}
		}
	}
	fout << maxInt - minInt+1	 - ssum << endl;
}