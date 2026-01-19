#include "bits/stdc++.h"
using namespace std;

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,M;
    cin>>N>>M;
    vector<string> Map(N);
    vector<vector<int>> Used(N,vector<int>(M,0));
    for(auto& r : Map) cin>>r;
    
    queue<pair<int,int>> Q;
    Used[0][0]=1;
    Q.push({0,0});
    while(!Q.empty())
    {
        auto [Cy,Cx]=Q.front();
        Q.pop();
        for(int i=0;i<4;++i)
        {
            int Ny=Cy+dy[i], Nx=Cx+dx[i];
            if(Ny<0 || Ny>=N || Nx<0 || Nx>=M || Used[Ny][Nx] || Map[Ny][Nx]=='0') continue;
            Q.push({Ny,Nx});
            Used[Ny][Nx]=Used[Cy][Cx]+1;
            if(Ny==N-1 && Nx==M-1) break;
        }
    }
    cout<<Used[N-1][M-1];
}