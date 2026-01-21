#include "bits/stdc++.h"
using namespace std;

int M,N,K;
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
vector<vector<int>> Map, Used;
int BFS(int Sy, int Sx)
{
    int Cnt=1;
    queue<pair<int,int>> Q;
    Q.push({Sy,Sx});
    Used[Sy][Sx]=1;
    while(!Q.empty())
    {
        auto [Cy,Cx]=Q.front();
        Q.pop();
        for(int i=0;i<4;++i)
        {
            int Ny=Cy+dy[i], Nx=Cx+dx[i];
            if(Ny<0 || Ny>=N || Nx<0 || Nx>=M || Used[Ny][Nx] || Map[Ny][Nx]) continue;
            Used[Ny][Nx]=1;
            Q.push({Ny,Nx});
            ++Cnt;
        }
    }
    return Cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>M>>K;
    Map.assign(N,vector<int>(M,0));
    Used.assign(N,vector<int>(M,0));
    while(K--)
    {
        int Lx=0, Ly=0, Rx=0, Ry=0;
        cin>>Lx>>Ly>>Rx>>Ry;
        for(int i=Ly;i<Ry;++i)
        {
            for(int j=Lx;j<Rx;++j)
            {
                Map[i][j]=1;
            }
        }
    }
    vector<int> Cnt;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            if(Used[i][j] || Map[i][j]) continue;
            Cnt.push_back(BFS(i,j));
        }
    }
    
    sort(Cnt.begin(),Cnt.end());
    cout<<Cnt.size()<<'\n';
    for(auto& c : Cnt) cout<<c<<' ';
}
