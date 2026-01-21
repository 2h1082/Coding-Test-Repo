#include "bits/stdc++.h"
using namespace std;

int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin>>T;
    
    while(T--)
    {
        int W,H;
        cin>>W>>H;
        vector<string> Map(H);
        vector<vector<int>> DistS(H,vector<int>(W,1e9)), DistF(H,vector<int>(W,1e9));
        int Sy=0, Sx=0;
        queue<pair<int,int>> Q;
        for(int i=0;i<H;++i)
        {
            cin>>Map[i];
            for(int j=0;j<W;++j)
            {
                if(Map[i][j]=='@')
                {
                    Sy=i; Sx=j;
                    DistS[i][j]=0;
                }
                else if(Map[i][j]=='*')
                {
                    Q.push({i,j});
                    DistF[i][j]=0;
                }
            }
        }
        // 불 퍼지는 시간 계산
        while(!Q.empty())
        {
            auto [Cy,Cx]=Q.front();
            Q.pop();
            for(int i=0;i<4;++i)
            {
                int Ny=Cy+dy[i], Nx=Cx+dx[i];
                if(Ny<0 || Ny>=H || Nx<0 || Nx>=W || DistF[Ny][Nx]!=1e9 || Map[Ny][Nx]=='#') continue;
                DistF[Ny][Nx]=DistF[Cy][Cx]+1;
                Q.push({Ny,Nx});
            }
        }
        // 상근이 도달 가능 여부 확인
        Q=queue<pair<int,int>>();
        Q.push({Sy,Sx});
        bool bIsPossible=false;
        while(!Q.empty() && !bIsPossible)
        {
            auto [Cy,Cx]=Q.front();
            Q.pop();
            for(int i=0;i<4;++i)
            {
                int Ny=Cy+dy[i], Nx=Cx+dx[i], NxtCost=DistS[Cy][Cx]+1;
                if(Ny<0 || Ny>=H || Nx<0 || Nx>=W) 
                {
                    cout<<NxtCost<<'\n';
                    bIsPossible=true;
                    break;
                }
                if(DistS[Ny][Nx]!=1e9 || Map[Ny][Nx]=='#' || NxtCost >= DistF[Ny][Nx]) continue;
                DistS[Ny][Nx]=NxtCost;
                Q.push({Ny,Nx});
            }
        }
        if(!bIsPossible) cout<<"IMPOSSIBLE\n";
    }
}