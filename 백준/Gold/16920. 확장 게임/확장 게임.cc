#include "bits/stdc++.h"
using namespace std;

int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,M,P;
    cin>>N>>M>>P;
    vector<int> Range(P+1,0), Cnt(P+1,0);
    vector<queue<pair<int,int>>> Q(P+1);
    for(int i=1;i<=P;++i) cin>>Range[i];
    vector<string> Map(N);
    for(int i=0;i<N;++i)
    {
        cin>>Map[i];
        for(int j=0;j<M;++j)
        {
            if(Map[i][j]!='.' && Map[i][j]!='#')
            {
                int Idx=Map[i][j]-'0';
                Q[Idx].push({i,j});
                ++Cnt[Idx];
            }
        }
    }
    while(1)
    {
        bool bIsMoved=false;
        for(int i=1;i<=P;++i)
        {
            for(int t=0;t<Range[i];++t)
            {
                if(Q[i].empty()) break;
                int Size=Q[i].size();
                while(Size--)
                {
                    auto Cy=Q[i].front().first, Cx=Q[i].front().second;
                    int CurNum=Map[Cy][Cx]-'0';
                    Q[i].pop();
                    for(int d=0;d<4;++d)
                    {
                        int Ny=Cy+dy[d], Nx=Cx+dx[d];
                        if(Ny<0 || Ny>=N || Nx<0 || Nx>=M || Map[Ny][Nx]!='.') continue;
                        Map[Ny][Nx]=Map[Cy][Cx];
                        ++Cnt[CurNum];
                        Q[i].push({Ny,Nx});
                        bIsMoved=true;
                    }
                }
                if(Q[i].empty()) break;
            }
        }
        if(!bIsMoved) break;
    }
     
    for(int i=1;i<=P;++i) cout<<Cnt[i]<<' ';
}