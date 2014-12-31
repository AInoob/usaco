/*
ID: zwang1
PROG: milk3
LANG: C++11
*/
#include <fstream>
using namespace std;
ofstream fout("milk3.out");
ifstream fin("milk3.in");

int input[3],answer[21],tempABC[3],tempInt[3],tempNum;

bool been[21][21][21];

void check(int aa,int bb,int cc)
{
 //   fout<<aa<<" "<<bb<<" "<<cc<<endl;
    if(aa==0)
    {
   //     fout<<"iiiiiiiiiiiiiiii"<<endl;
        answer[cc]=true;
    }
}

bool pouring(int from,int to)
{
 //   fout<<"---------"<<from<<" "<<to<<"----"<<tempInt[0]<<" "<<tempInt[1]<<" "<<tempInt[2]<<endl;
    if(tempInt[from]==0||tempInt[to]==input[to])
        return false;
    else
    {
        for(int i=0;i<3;++i)
            tempABC[i]=tempInt[i];
        tempNum=tempInt[from]+tempInt[to];
        if(tempNum<=input[to])
        {
            tempABC[to]=tempNum;
            tempABC[from]=0;
        }
        else
        {
            tempABC[to]=input[to];
            tempABC[from]=tempNum-input[to];
        }
  //      fout<<"!!!!!"<<tempABC[0]<<" "<<tempABC[1]<<" "<<tempABC[2]<<endl;
        return true;
    }
}

void pour(int aa,int bb,int cc)
{
    if(been[aa][bb][cc])
        return;
    been[aa][bb][cc]=true;
    check(aa,bb,cc);
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            if(j!=i)
            {
                tempInt[0]=aa;
                tempInt[1]=bb;
                tempInt[2]=cc;
                if(pouring(i,j))
                {
                    if(!been[tempABC[0]][tempABC[1]][tempABC[2]])
                    {
                        pour(tempABC[0],tempABC[1],tempABC[2]);
                    }
                }
            }
        }
    }   
}

int main()
{
    fin>>input[0]>>input[1]>>input[2];
    pour(0,0,input[2]);
    int tt=0;
    for(int i=0;i<21;++i)
    {
        if(answer[i])
            ++tt;
    }
    --tt;
    int ii,jj;
    for(jj=0,ii=0;ii<tt;++jj)
    {
        if(answer[jj])
        {
            ++ii;
            fout<<jj<<" ";
        }
    }
    while(!answer[jj])
        ++jj;
    fout<<jj<<endl;
    return 0;
}
