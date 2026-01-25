#include "bits/stdc++.h"
using namespace std;

int dy[]={-1,1,0,0,-2,-1,1,2,2,1,-1,-2};
int dx[]={0,0,-1,1,1,2,2,1,-1,-2,-2,-1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int K,W,H;
    cin>>K>>W>>H;
    
    vector<vector<int>> Map(H,vector<int>(W,0));
    vector<vector<vector<int>>> Dist(H,vector<vector<int>>(W,vector<int>(K+1,1e9)));
    for(auto& r : Map)
    {
        for(auto& c : r)
        {
            cin>>c;
        }
    }
    queue<tuple<int,int,int>> Q;
    Q.push({0,0,K});
    Dist[0][0][K]=0;
    bool bIsFound=false;
    while(!Q.empty() && !bIsFound)
    {
        auto [Cy,Cx,Cnt]=Q.front();
        Q.pop();
        for(int i=0;i<12;++i)
        {
            int Ny=Cy+dy[i], Nx=Cx+dx[i], NxtCnt=Cnt;
            if(Ny<0 || Ny>=H || Nx<0 || Nx>=W)              continue;
            if(i>3)
            {
                if(Cnt<1) break;
                else      --NxtCnt;
            }
            if(Map[Ny][Nx]==1 || Dist[Ny][Nx][NxtCnt]!=1e9) continue;
            Dist[Ny][Nx][NxtCnt]=Dist[Cy][Cx][Cnt]+1;
            if(Ny==H-1 && Nx==W-1) 
            {
                bIsFound=true;
                break;
            }
            Q.push({Ny,Nx,NxtCnt});
        }
    }
    int Ans=*min_element(Dist[H-1][W-1].begin(), Dist[H-1][W-1].end());
    if(Ans==1e9) cout<<-1;
    else         cout<<Ans;
}