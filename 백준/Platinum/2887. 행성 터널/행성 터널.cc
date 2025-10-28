#include <bits/stdc++.h>

using namespace std;
using ll=long long;
struct Point
{
    int x, y, z, ID;
};
int main()
{
    int N=0;
    cin>>N;
    
    vector<Point> Planet(N);
    for(int i=0;i<N;++i)
    {
        cin>>Planet[i].x>>Planet[i].y>>Planet[i].z;
        Planet[i].ID=i;
    }
    vector<vector<pair<int,int>>> Graph(N);
    
    auto AddEdges = [&](auto key)
    {
        sort(Planet.begin(),Planet.end(),[&](const Point& a, const Point& b){
           return key(a)<key(b); 
        });
        for(int i=0;i<N-1;++i)
        {
            int w=abs(key(Planet[i])-key(Planet[i+1]));
            int v1=Planet[i].ID, v2=Planet[i+1].ID;
            Graph[v1].push_back({w,v2});
            Graph[v2].push_back({w,v1});
        }
    };
    AddEdges([](const Point& a){return a.x;});
    AddEdges([](const Point& a){return a.y;});
    AddEdges([](const Point& a){return a.z;});
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,0});
    vector<bool> Visited(N,false);
    ll Total=0;
    int Cnt=0;
    while(!pq.empty()&&Cnt<N-1)
    {
        auto [Cost,Cur]=pq.top();
        pq.pop();
        if(Visited[Cur]) continue;
        Visited[Cur]=true;
        Total+=(ll)Cost;
        for(auto& [w,Next]: Graph[Cur])
        {
            if(Visited[Next]) continue;
            pq.push({w,Next});
        }
    }
    cout<<Total;
}