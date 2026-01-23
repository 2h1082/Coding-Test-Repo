#include "bits/stdc++.h"
using namespace std;

int dz[]={0,0,0,0,-1,1};
int dy[]={-1,1,0,0,0,0};
int dx[]={0,0,-1,1,0,0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(1)
    {
        int L,R,C;
        cin>>L>>R>>C;
        if(!L && !R && !C) break;
        
        vector<vector<string>> Map(L,vector<string>(R));
        vector<vector<vector<int>>> Dist(L,vector<vector<int>>(R,vector<int>(C,-1)));
        queue<tuple<int,int,int>> Q;
        for(int k=0;k<L;++k) 
        {
            for(int i=0;i<R;++i) 
            {
                cin>>Map[k][i];
                for(int j=0;j<C;++j)
                {
                    if(Map[k][i][j]=='S') 
                    {
                        Q.push({k,i,j});
                        Dist[k][i][j]=0;
                    }
                }
            }
        }
        
        bool bIsPossible=false;
        while(!Q.empty())
        {
            auto [Cz,Cy,Cx]=Q.front();
            Q.pop();
            for(int i=0;i<6;++i)
            {
                int Nz=Cz+dz[i], Ny=Cy+dy[i], Nx=Cx+dx[i];
                if(Nz<0 || Nz>=L || Ny<0 || Ny>=R || Nx<0 || Nx>=C || Dist[Nz][Ny][Nx]!=-1 || Map[Nz][Ny][Nx]=='#') continue;                
                Dist[Nz][Ny][Nx]=Dist[Cz][Cy][Cx]+1;
                if(Map[Nz][Ny][Nx]=='E')
                {
                    cout<<"Escaped in "<<Dist[Nz][Ny][Nx]<<" minute(s).\n";
                    bIsPossible=true;
                    break;
                }
                Q.push({Nz,Ny,Nx});
            }
        }
        if(!bIsPossible) cout<<"Trapped!\n";
    }
}