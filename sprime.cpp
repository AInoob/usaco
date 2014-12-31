/*
ID: zwang1
PROG: sprime
LANG: C++11
*/
#include <fstream>
using namespace std;
ofstream fout("sprime.out");
ifstream fin("sprime.in");

int n,maxInt;

bool prime(int num)
{
    if(num==2)
        return true;
    if(num==1)
        return false;
    maxInt=num;
    for(int i=2;i<=maxInt;++i)
    {
        if(num%i==0)
            return false;
        maxInt=num/i;
    }
    return true;
}

void dfs(int num,int d)
{
    if(d==n)
        fout<<num<<endl;
    else
    {
        for(int i=1;i<10;++i)
        {
            if(i>3)
                ++i;
            if(prime(num*10+i))
            {
                dfs(num*10+i,d+1);
            }
        }
    }
}

int main()
{
    fin>>n;
    dfs(0,0);
    return 0;
}
