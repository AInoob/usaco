/*
ID: zwang1
PROG: crypt1
LANG: C++11
*/
#include <fstream>
using namespace std;
ofstream fout("crypt1.out");
ifstream fin("crypt1.in");

int n, input[9], map[5], temp, t1, t2, t3, ans = 0;

bool contains1(int a)
{
	for (int i = 0; i < n; i++)
	{
		if (input[i] == a)
			return true;
	}
	return false;
}

bool contains(int a)
{
	while (a != 0)
	{
		temp = a % 10;
		if (!contains1(temp))
			return false;
		a /= 10;
	}
	return true;
}

bool inrange(int a,int b)
{
	if (a*b < 1000)
		return true;
	return false;
}

void dfs(int a)
{
	if (a == 5)
	{
		t1 = map[2] * 100 + map[1] * 10 + map[0];
		t3 = t1*(map[3] + map[4] * 10);
		if (inrange(t1,map[4])&&contains(t1*map[4])&&contains(t3))
		{
			++ans;
		}
		return;
	}
	else
	{
		if (a == 4)
		{
			t1 = map[2] * 100 + map[1] * 10 + map[0];
			t2 = map[3];
			if (inrange(t1,t2)&&contains(t1*t2))
			{
				for (int i = 0; i < n; i++)
				{
					map[a] = input[i];
					dfs(a + 1);
				}
			}
			return;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				map[a] = input[i];
				dfs(a + 1);
			}
		}
	}
}

int main()
{
	fin >> n;
	for (int i = 0; i < n; ++i)
	{
		fin >> input[i];
	}
	dfs(0);
	fout << ans << endl;
}