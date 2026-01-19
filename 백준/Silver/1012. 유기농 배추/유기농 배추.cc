#include "bits/stdc++.h"
using namespace std;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin>>T;
    
    while(T--)
    {
        int M,N,K;
        cin>>M>>N>>K;
        vector<vector<int>> Map(N,vector<int>(M,0));
        vector<pair<int,int>> Cand;
        while(K--)
        {
            int X,Y;
            cin>>X>>Y;
            Map[Y][X]=1;
            Cand.push_back({Y,X});
        }
        int Cnt=0;
        for(auto& [Sy, Sx]:Cand)
        {
            if(!Map[Sy][Sx]) continue;
            ++Cnt;
            queue<pair<int,int>> Q;
            Q.push({Sy,Sx});
            Map[Sy][Sx]=0;
            while(!Q.empty())
            {
                auto [Cy,Cx]=Q.front();
                Q.pop();
                for(int i=0;i<4;++i)
                {
                    int Ny=Cy+dy[i], Nx=Cx+dx[i];
                    if(Ny<0 || Ny>=N || Nx<0 || Nx>=M || !Map[Ny][Nx]) continue;
                    Q.push({Ny,Nx});
                    Map[Ny][Nx]=0;
                }
            }
        }
        cout<<Cnt<<'\n';
    }
}