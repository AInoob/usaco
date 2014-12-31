// 2014.12.01_beads.cpp : Defines the entry point for the console application.
//
/*
ID: zwang1
PROG: beads
LANG: C++11
*/
#include <fstream>

using namespace std;


char input[351], theSign;
int numbersOfBeads, numberOfBreak = 0, thePosition = 0, theAnswer = 0, trueAnswer;


int main()
{
	ofstream fout("beads.out");
	ifstream fin("beads.in");
	fin >> numbersOfBeads;
	for (int i = 0; i < numbersOfBeads; i++)
	{
		fin >> input[i];
	}
	for (int i = 0; i < numbersOfBeads; i++)
	{
		thePosition = i;
		numberOfBreak = 0;
		theAnswer = 0;
		while (input[thePosition] == 'w')
		{
			thePosition++;
			theAnswer++;
		}
		theSign = input[thePosition];
		while (numberOfBreak < 2 && theAnswer < numbersOfBeads)
		{
			thePosition++;
			thePosition %= numbersOfBeads;
			if (input[thePosition] != 'w'&&input[thePosition] != theSign)
			{
				theSign = input[thePosition];
				numberOfBreak++;
			}
			theAnswer++;
		}
		trueAnswer = trueAnswer < theAnswer ? theAnswer : trueAnswer;
	}
	fout << trueAnswer << endl;
	return 0;
}