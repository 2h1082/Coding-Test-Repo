#include "bits/stdc++.h"
using namespace std;
vector<vector<int>> Map;
vector<vector<bool>> Visited;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
int N,L,R;
bool UnionCells(int sy, int sx)
{
    Visited[sy][sx]=true;
    queue<pair<int,int>> q;
    q.push({sy,sx});
    int Sum=Map[sy][sx];
    vector<pair<int,int>> Union;
    while(!q.empty())
    {
        int cy=q.front().first, cx=q.front().second;
        Union.push_back({cy,cx});
        q.pop();
        for(int i=0;i<4;++i)
        {
            int ny=dy[i]+cy, nx=dx[i]+cx;
            if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
            
            int Diff=abs(Map[ny][nx]-Map[cy][cx]);
            if(Visited[ny][nx] || Diff<L || Diff>R) continue;
            
            q.push({ny,nx});
            Visited[ny][nx]=true;
            Sum+=Map[ny][nx];
        }
    }
    int Denominator=Union.size();
    if(Denominator<=1) return false;
    int Avg=Sum/Denominator;
    for(auto& [y, x] : Union)
    {
        Map[y][x]=Avg;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>L>>R;
    
    Map.assign(N,vector<int>(N,0));
    for(auto& r : Map)
    {
        for(auto& c : r)
        {
            cin>>c;
        }
    }
    int Ans=0;
    while(1)
    {
        Visited.assign(N,vector<bool>(N,false));
        bool bIsChanged=false;
        
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<N;++j)
            {
                if(Visited[i][j]) continue;
                if(UnionCells(i,j)) bIsChanged=true;
            }
        }
        
        if(bIsChanged) Ans++;
        else           break;
    }
    cout<<Ans;
}