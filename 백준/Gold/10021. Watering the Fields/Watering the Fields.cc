#include "bits/stdc++.h"
using namespace std;

struct Edge
{
    int Cost,V1,V2;
    
    bool operator < (const Edge& other) const
    {
        return Cost < other.Cost;
    }
};
struct UF
{
    vector<int> Parent, Size;
    
    UF(int N)
    {
        Parent.resize(N);
        Size.assign(N,1);
        iota(Parent.begin(),Parent.end(),0);
    }
    int Find(int v)
    {
        if(v!=Parent[v]) return Parent[v]=Find(Parent[v]);
        return v;
    }
    bool Union(int v1, int v2)
    {
        int r1=Find(v1), r2=Find(v2);
        if(r1==r2) return false;
        
        if(Size[r1]<Size[r2]) swap(r1,r2);
        
        Parent[r2]=r1;
        Size[r1]+=Size[r2];
        return true;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,C;
    cin>>N>>C;
    
    vector<pair<int,int>> Dots(N);
    for(auto& [x,y] : Dots) cin>>x>>y;
    
    vector<Edge> Edges;
    Edges.reserve(N*(N-1)/2);
    
    for(int i=0;i<N;++i)
    {
        for(int j=i+1;j<N;++j)
        {
            int dx=Dots[i].first-Dots[j].first, dy=Dots[i].second-Dots[j].second;
            int Cost=dx*dx + dy*dy;
            if(Cost >= C) Edges.push_back({Cost,i,j});
        }
    }
    sort(Edges.begin(),Edges.end());
    
    UF U(N);
    int Ans=0, Cnt=0;
    for(auto& [c,v1,v2] : Edges)
    {
        if(U.Union(v1,v2)) 
        {
            Ans+=c;
            Cnt++;
            if(Cnt==N-1) break;
        }
    }
    if(Cnt!=N-1) cout<<-1;
    else         cout<<Ans;
}