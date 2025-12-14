#include "bits/stdc++.h"
using namespace std;

int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int R,C;
    cin>>R>>C;
    
    queue<tuple<int,int,int>> q;
    int Sx=0, Sy=0;
    vector<string> Map(R);
    vector<vector<int>> MinTime(R,vector<int>(C,1e9)), MinTimeJ(R,vector<int>(C,1e9));
    for(int i=0;i<R;++i)
    {
        cin>>Map[i];
        for(int j=0;j<C;++j)
        {
            if(Map[i][j]=='F') 
            {
                q.push({i,j,0});
                MinTime[i][j]=0;
            }
            else if(Map[i][j]=='J')
            {
                Sy=i;
                Sx=j;
                MinTimeJ[i][j]=0;
            }
        }
    }
    
    // 불 번짐 BFS
    while(!q.empty())
    {
        auto [Cy,Cx,CurTime]=q.front();
        q.pop();
        for(int i=0;i<4;++i)
        {
            int Ny=Cy+dy[i], Nx=Cx+dx[i];
            if(Ny<0 || Ny>=R || Nx<0 || Nx>=C) continue;
            
            if(Map[Ny][Nx]=='.' && MinTime[Ny][Nx]==1e9) 
            {
                MinTime[Ny][Nx]=CurTime+1;
                q.push({Ny,Nx,MinTime[Ny][Nx]});
            }
        }
    }
    // 정훈이의 탈출 BFS
    q.push({Sy,Sx,0});
    while(!q.empty())
    {
        auto [Cy,Cx,CurTime]=q.front();
        q.pop();
        for(int i=0;i<4;++i)
        {
            int Ny=Cy+dy[i], Nx=Cx+dx[i], NxtTime=CurTime+1;
            if(Ny<0 || Ny>=R || Nx<0 || Nx>=C) 
            {
                cout<<NxtTime;
                return 0;
            }
            
            if(MinTimeJ[Ny][Nx]!=1e9) continue;
            
            if(Map[Ny][Nx]=='.' && MinTime[Ny][Nx] > NxtTime) 
            {
                MinTimeJ[Ny][Nx]=NxtTime;
                q.push({Ny,Nx,NxtTime});
            }
        }
    }
    cout<<"IMPOSSIBLE";
}