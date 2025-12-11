#include "bits/stdc++.h"
using namespace std;

int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int Num=1;
    while(1)
    {
        int N;
        cin>>N;
        
        if(!N) break;
        vector<vector<int>> Map(N,vector<int>(N,0)), Dist(N,vector<int>(N,1e9));
        for(auto& r : Map)
        {
            for(auto& c : r)
            {
                cin>>c;
            }
        }
        
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;
        pq.push({Map[0][0],0,0});
        Dist[0][0]=Map[0][0];
        while(!pq.empty())
        {
            auto [Cost,cy,cx]=pq.top();
            pq.pop();
            if(Dist[cy][cx]<Cost) continue;
            
            for(int i=0;i<4;++i)
            {
                int ny=cy+dy[i], nx=cx+dx[i];
                if(ny<0 || nx<0 || ny>=N || nx>=N) continue;
                
                int NxtCost=Map[ny][nx]+Cost;
                if(NxtCost < Dist[ny][nx])
                {
                    Dist[ny][nx]=NxtCost;
                    pq.push({NxtCost,ny,nx});
                }
            }
        }
        
        cout<<"Problem "<<Num<<": "<<Dist[N-1][N-1]<<'\n';
        Num++;
    }
}