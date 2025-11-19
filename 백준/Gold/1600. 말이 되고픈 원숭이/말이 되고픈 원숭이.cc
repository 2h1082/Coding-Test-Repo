#include "bits/stdc++.h"
using namespace std;
// 상 좌우, 하 좌우, 우 상하, 좌 상하
int dx[12]={0,0,-1,1,-1,1,-1,1,2,2,-2,-2};
int dy[12]={-1,1,0,0,-2,-2,2,2,-1,1,-1,1};

struct P
{
    int y,x,Cnt,Rem;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int K, W, H;
    cin>>K>>W>>H;
    vector<vector<int>> Map(H,vector<int>(W,0));
    vector<vector<vector<bool>>> Visited(H,vector<vector<bool>>(W,vector<bool>(K+1,false)));
    for(auto& r : Map)
        for(auto& c : r)
            cin>>c;
    
    queue<P> q;
    q.push({0,0,0,K});
    Visited[0][0][K]=true;
    int Res=-1;
    while(!q.empty())
    {
        int cy=q.front().y, cx=q.front().x, Cnt=q.front().Cnt, Rem=q.front().Rem;
        q.pop();
        if(cy==H-1 && cx==W-1)
        {
            Res=Cnt;
            break;
        }
        for(int i=0;i<12;++i)
        {
            if(Rem<=0 && i>3) break;
            int ny=cy+dy[i], nx=cx+dx[i];
            int NxtRem=Rem - (i>3 ? 1 : 0);
            if(ny<0 || ny>=H || nx<0 || nx>=W || Visited[ny][nx][NxtRem] || Map[ny][nx]) continue;
            
            Visited[ny][nx][NxtRem]=true;
            q.push({ny,nx,Cnt+1,NxtRem});
        }
    }
    cout<<Res;
}