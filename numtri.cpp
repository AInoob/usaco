/*
ID: zwang1
PROG: numtri
LANG: C++11
*/
#include <fstream>
using namespace std;
ofstream fout("numtri.out");
ifstream fin("numtri.in");

int n,input[1000][1000],result[1000][1000],maxInt=0;

int getMax(int x,int y)
{
    if(x==0)
        return result[0][y-1];
    if(x==y)
        return result[x-1][y-1];
    return result[x][y-1]>result[x-1][y-1]?result[x][y-1]:result[x-1][y-1];
}

int main()
{
    fin>>n;
    for(int j=0;j<n;++j)
    {
        for(int i=0;i<=j;++i)
        {
            fin>>input[i][j];
        }
    }
    result[0][0]=input[0][0];
    for(int j=1;j<n;++j)
    {
        for(int i=0;i<=j;++i)
        {
            result[i][j]=getMax(i,j)+input[i][j];
        }
    }
    for(int i=0;i<n;++i)
    {
        if(maxInt<result[i][n-1])
            maxInt=result[i][n-1];
    }
    fout<<maxInt<<endl;
    return 0;
}
