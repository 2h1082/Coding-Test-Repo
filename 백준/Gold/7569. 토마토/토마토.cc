#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int dx[6]={0,0,-1,1,0,0};
int dy[6]={-1,1,0,0,0,0};
int dz[6]={0,0,0,0,-1,1};
int MaxDay=0;

int main()
{
    int N,M,H;  
    cin>>M>>N>>H;
    vector<vector<vector<int>>> Box(N,vector<vector<int>>(M,vector<int>(H,0)));
    int Green=0;
    queue<vector<int>> q;
    for(int k=0;k<H;++k)
    {
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<M;++j)
            {
                cin>>Box[i][j][k];
                if(Box[i][j][k]==0)
                {
                    Green++;
                }
                else if(Box[i][j][k]==1)
                {
                    q.push({j,i,k,0});
                }
            }
        }
    }
    if(!Green)
    {
        cout<<"0";
        return 0;
    }

    while (!q.empty())
    {
        int CurX=q.front()[0];
        int CurY=q.front()[1];
        int CurZ=q.front()[2];
        int CurDayCount=q.front()[3];
        MaxDay=max(MaxDay,CurDayCount);
        q.pop();
        for(int i=0;i<6;++i)
        {
            int NextX=CurX+dx[i];
            int NextY=CurY+dy[i];
            int NextZ=CurZ+dz[i];
            if(NextX>=0&&NextX<M&&NextY>=0&&NextY<N&&NextZ>=0&&NextZ<H
               &&Box[NextY][NextX][NextZ]==0)
            {
                q.push({NextX,NextY,NextZ,CurDayCount+1});
                Box[NextY][NextX][NextZ]=1;
                Green--;
            }
        }
    }
    
    if(Green>0)
    {
        cout<<"-1";
    }
    else
    {
        cout<<MaxDay;
    }
}