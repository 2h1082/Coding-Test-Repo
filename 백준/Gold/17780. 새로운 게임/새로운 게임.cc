#include "bits/stdc++.h"
using namespace std;

int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,-1,1};
struct Horse
{
    int x,y,d;
};
int ReverseDir(int D)
{
    if(D==1) return 2;
    if(D==2) return 1;
    if(D==3) return 4;
    return 3;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,K;
    cin>>N>>K;
    
    vector<vector<int>> Map(N,vector<int>(N,0));
    for(auto& r : Map)
    {
        for(auto& c : r)
        {
            cin>>c;
        }
    }
    vector<Horse> H(K);
    vector<vector<vector<int>>> Board(N,vector<vector<int>>(N));
    for(int i=0;i<K;++i) 
    {
        cin>>H[i].y>>H[i].x>>H[i].d;
        H[i].y--; H[i].x--;
        Board[H[i].y][H[i].x].push_back(i);
    }
    
    for(int Turn=1;Turn<=1000;++Turn)
    {
        for(int i=0;i<K;++i)
        {
            int y=H[i].y, x=H[i].x, d=H[i].d;
            auto& Cur=Board[y][x];
            if(Cur.front()!=i) continue;
            
            int ny=y+dy[d], nx=x+dx[d];
            if(ny<0 || ny>=N || nx<0 || nx>=N || Map[ny][nx]==2)
            {
                d=ReverseDir(d);
                H[i].d=d;
                ny=y+dy[d];
                nx=x+dx[d];
                if(ny<0 || ny>=N || nx<0 || nx>=N || Map[ny][nx]==2) continue;
            }
            
            vector<int> Moving(Cur.begin(),Cur.end());
            Cur.clear();
            
            if(Map[ny][nx]==1) reverse(Moving.begin(),Moving.end());
            
            for(int h : Moving)
            {
                Board[ny][nx].push_back(h);
                H[h].y=ny;
                H[h].x=nx;
            }
            
            if(Board[ny][nx].size()>=4)
            {
                cout<<Turn;
                return 0;
            }
        }
    }
    cout<<-1;
}