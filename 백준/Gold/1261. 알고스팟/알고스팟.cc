#include "bits/stdc++.h"
using namespace std;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
struct P
{
    int y,x,Cnt;  
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M;
    cin>>M>>N;
    vector<string> Map(N);
    vector<vector<int>> Min(N,vector<int>(M,1e9));
    
    for(auto& r : Map)
    {
        cin>>r;
    }
    deque<P> q;
    q.push_front({0,0,0});
    Min[0][0]=0;
    while(!q.empty())
    {
        int cy=q.front().y, cx=q.front().x, Cnt=q.front().Cnt;
        q.pop_front();
        if(cy==N-1 && cx==M-1)
        {
            cout<<Cnt;
            break;
        }
        if(Min[cy][cx]<Cnt) continue;
        for(int i=0;i<4;++i)
        {
            int ny=cy+dy[i], nx=cx+dx[i];
            if(ny<0 || ny>=N || nx<0 || nx>=M) continue;

            int NxtCnt=Cnt + (Map[ny][nx]=='1' ? 1 : 0);
            if (NxtCnt >= Min[ny][nx]) continue;
            
            Min[ny][nx]=NxtCnt;
            if(Map[ny][nx]=='1')
            {
                q.push_back({ny,nx,NxtCnt});
            } 
            else
            {
                q.push_front({ny,nx,NxtCnt});
            }
        }
    }
}