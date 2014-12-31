/* 
ID: zwang1 
PROG: wormhole
LANG: C++11
*/
#include <fstream>
using namespace std;
ofstream fout("wormhole.out");
ifstream fin("wormhole.in");

int n,input[12][2],previousInt,minInt,cursorPos,map[12][12],maxY=0,minPos,answer=0,tempPos,tempInt,tempAnswer;
bool checkMap[12];

void arrange(int k)
{
    cursorPos=-1;
    previousInt=-1;
    for(int i=0;i<n;)
    {
        int j=0;
        while(input[j][k]<=previousInt)
        {
            ++j;
        }
        minInt=input[j][k];
        ++j;
        for(;j<n;++j)
        {
            if(input[j][k]>previousInt&&minInt>input[j][k])
            {
                minInt=input[j][k];
            }
        }
        cursorPos++;
        previousInt=minInt;
        for(j=0;j<n;++j)
        {
            if(minInt==input[j][k])
            {
                input[j][k]=cursorPos;
                ++i;
            }
        }
        maxY++;
    }
}

void shrink()
{
    int tempNum,tempList[12];
    for(int i=0;i<maxY;++i)
    {
        tempNum=0;
        for(int j=0;j<n;++j)
        {
            if(input[j][1]==i)
            {
                tempList[tempNum]=j;
                tempNum++;
            }
        }
        previousInt=-2;
        cursorPos=0;
        for(int j=0;j<tempNum;++j)
        {
            int k=0;
            while(input[tempList[k]][0]<=previousInt)
            {
                ++k;
            }
            minPos=k;
            ++k;
            for(;k<tempNum;++k)
            {
                if(input[tempList[minPos]][0]>input[tempList[k]][0]&&input[tempList[k]][0]>previousInt)
                {
                    minPos=k;
                }
            }
            previousInt=input[tempList[minPos]][0];
            input[tempList[minPos]][0]=cursorPos;
            ++cursorPos;
        }
        if(cursorPos>maxY)
            maxY=cursorPos;
    }
}

void check()
{
    int nn,nnMap[12];
    for(int i=0;i<maxY;++i)
    {
        int k=0;
        while(map[k][i]!=0)
        {
            nn=0;
            tempPos=i+100+k*100;
            while(tempPos!=0)
            {
                for(int j=0;j<nn;++j)
                {
                    if(tempPos==nnMap[j])
                    {
                        ++answer;
                        return;
                    }
                }
                nnMap[nn]=tempPos;
                ++nn;
                tempPos=map[tempPos/100][tempPos%100];
            }
            ++k;
        }

    }
}

void match(int level)
{
    if(level==n)
    {
        check();
    }
    else
    {
        int a,i=0;
        while(checkMap[i]==true)
        {
            ++i;
        }
        a=i;
        ++level;
        checkMap[a]=true;
        for(;i<n;++i)
        {
            if(checkMap[i]==false)
            {
                ++level;
                map[input[a][0]][input[a][1]]=input[i][0]*100+100+input[i][1];
                map[input[i][0]][input[i][1]]=input[a][0]*100+100+input[a][1];
                checkMap[i]=true;
                match(level);
                --level;
                checkMap[i]=false;
            }
        }
        --level;
        checkMap[a]=false;
    }
}

int main()
{
    fin>>n;
    for(int i=0;i<n;++i)
    {
        fin>>input[i][0]>>input[i][1];
    }
    arrange(1);
    shrink();
    match(0);
    fout<<answer<<endl;
    return 0;
}
