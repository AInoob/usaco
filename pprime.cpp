/*
ID: zwang1
PROG: pprime
LANG: C++11
*/
#include <fstream>
using namespace std;
ofstream fout("pprime.out");
ifstream fin("pprime.in");

int a,b,tempInt1,tempInt2,maxInt;

bool pal(int num)
{
    tempInt1=0;
    tempInt2=num;
    while(tempInt2!=0)
    {
        tempInt1*=10;
        tempInt1+=tempInt2%10;
        tempInt2/=10;
    }
    return num==tempInt1;
}

bool prime(int num)
{
    maxInt=num;
    for(int i=3;i<maxInt;++i)
    {
        if(num%i==0)
            return false;
        else
            maxInt=num/i;
    }
    return true;
}

int outOfRange(int num)
{
    if(num<100)
        return num;
    tempInt1=num;
    tempInt2=0;
    while(tempInt1>=100)
    {
        tempInt1/=100;
        ++tempInt2;
    }
    if(tempInt1>=10)
    {
        tempInt1=1;
        while(tempInt2>=0)
        {
            tempInt1*=100;
            --tempInt2;
        }
        return tempInt1+1;
    }
    else
    {
        return num;
    }
}

int main()
{
    fin>>a>>b;
    if(a%2==0)
        ++a;
    for(int i=a;i<=b;i+=2)
    {
        i=outOfRange(i);
        if(pal(i)&&prime(i))
            fout<<i<<endl;
    }
    return 0;
}
