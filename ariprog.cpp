/*
ID: zwang1
PROG: ariprog
LANG: C++11
*/
#include <fstream>
#include <set>
using namespace std;
ofstream fout("ariprog.out");
ifstream fin("ariprog.in");

int n,m,maxInt=0,tempInt,startInt;
bool bisquare[125001],answer=false;

int main()
{
    fin>>n>>m;
    for(int i=0;i<=m;++i)
    {
        for(int j=i;j<=m;++j)
        {
            tempInt=i*i+j*j;
            bisquare[tempInt]=true;
            if(tempInt>maxInt)
                maxInt=tempInt;
        }
    }
    for(int diff=1;diff<=maxInt/(n-1);diff++)
    {
        for(int k=0;k<=maxInt-diff*(n-1);++k)
        {
            while(!bisquare[k])
                ++k;
            for(int i=k,startInt=i;i<=maxInt;i+=diff)
            {
                if(!bisquare[i])
                    break;
                if((i-startInt)/diff==n-1)
                {
                    fout<<startInt<<" "<<diff<<endl;
                    answer=true;
                }
            }
        }
    }
    if(!answer)
    {
        fout<<"NONE"<<endl;
    }
    return 0;
}
