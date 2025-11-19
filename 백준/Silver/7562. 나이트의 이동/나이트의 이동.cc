#include "bits/stdc++.h"
using namespace std;
// 상 좌우, 하 좌우, 우 상하, 좌 상하
int dx[8]={-1,1,-1,1,2,2,-2,-2};
int dy[8]={-2,-2,2,2,1,-1,1,-1};
struct P
{
    int y,x,Cnt;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T=0;
    cin>>T;
    while(T--)
    {
        int l=0;
        cin>>l;
        vector<vector<bool>> Visited(l,vector<bool>(l,false));
        int sx,sy, tx, ty;
        cin>>sx>>sy>>tx>>ty;
        
        queue<P> q;
        q.push({sy,sx,0});
        Visited[sy][sx]=true;
        while(!q.empty())
        {
            auto [cy,cx,Cnt]=q.front();
            q.pop();
            if(cy==ty && cx==tx)
            {
                cout<<Cnt<<'\n';
                break;
            }
            for(int i=0;i<8;++i)
            {
                int nx=cx+dx[i];
                int ny=cy+dy[i];
                if(nx<0 || nx>=l || ny<0 || ny>=l || Visited[ny][nx]) continue;
                
                q.push({ny,nx,Cnt+1});
                Visited[ny][nx]=true;
            }
        }
    }
}