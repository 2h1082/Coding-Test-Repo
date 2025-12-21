#include "bits/stdc++.h"
using namespace std;

int N,K;
int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,-1,1};
struct State
{
    int y,x,d;
};
int ReverseDir(int d)
{
    if(d==1) return 2;
    if(d==2) return 1;
    if(d==3) return 4;
    return 3;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>K;
    
    vector<vector<int>> A(N,vector<int>(N,0));
    vector<vector<vector<int>>> Horse(N,vector<vector<int>>(N));
    for(auto& r : A)
    {
        for(auto& c : r)
        {
            cin>>c;
        }
    }
    
    vector<State> Hs(K);
    for(int i=0;i<K;++i)
    {
        cin>>Hs[i].y>>Hs[i].x>>Hs[i].d;
        Hs[i].y--;
        Hs[i].x--;
        Horse[Hs[i].y][Hs[i].x].push_back(i);
    }
    
    for(int Turn=1;Turn<=1000;++Turn)
    {
        for(int i=0;i<K;++i)
        {
            auto [y,x,d]=Hs[i];
            
            int ny=y+dy[d], nx=x+dx[d];
            if(ny<0 || ny>=N || nx<0 || nx>=N || A[ny][nx]==2) 
            {
                d=ReverseDir(d);
                Hs[i].d=d;
                ny=y+dy[d];
                nx=x+dx[d];
                if(ny<0 || ny>=N || nx<0 || nx>=N || A[ny][nx]==2) continue;
            }
            
            auto& Cur=Horse[y][x];
            int Idx=find(Cur.begin(),Cur.end(),i)-Cur.begin();
            
            vector<int> Moving(Cur.begin()+Idx,Cur.end());
            Cur.erase(Cur.begin()+Idx,Cur.end());
            
            if(A[ny][nx]==1)
            {
                reverse(Moving.begin(),Moving.end());
            }
            
            for(int h : Moving) 
            {
                Horse[ny][nx].push_back(h);
                Hs[h].x=nx;
                Hs[h].y=ny;                
            }
            if(Horse[ny][nx].size()>=4)
            {
                cout<<Turn;
                return 0;
            }
        }
    }
    cout<<-1;
}