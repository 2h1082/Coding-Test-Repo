#include <bits/stdc++.h>

using namespace std;
using Edge=pair<int,int>;
using ll=long long;
struct Node
{
    ll Cost=0;
    vector<int> Arr;
    bool operator>(const Node& Other) const
    {
        return Cost>Other.Cost;
    }
};

string Encode(const vector<int>& Arr)
{
    string Res;
    for(auto& a : Arr) Res+=to_string(a)+",";
    return Res;
}

int main()
{
    int N=0;
    cin>>N;
    vector<int> Arr(N,0);
    for(auto& a : Arr) cin>>a;
    int M=0;
    cin>>M;
    vector<vector<Edge>> Graph(N,vector<Edge>());
    while(M--)
    {
        int l,r,c;
        cin>>l>>r>>c;
        l--; r--;
        Graph[l].push_back({c,r});
        Graph[r].push_back({c,l});
    }
    vector<int> Target=Arr;
    sort(Target.begin(),Target.end());
    
    priority_queue<Node,vector<Node>,greater<Node>> pq;
    pq.push({0,Arr});
    unordered_map<string, ll> Dist;
    Dist[Encode(Arr)]=0;
    while(!pq.empty())
    {
        auto [Cost,CurArr]=pq.top();
        pq.pop();
        if(CurArr==Target)
        {
            cout<<Cost;
            return 0;
        }
        string CurKey=Encode(CurArr);
        if(Dist[CurKey]<Cost) continue;
        
        for(int i=0;i<N;++i)
        {
            for(auto& Cell : Graph[i])
            {
                auto NextArr=CurArr;
                swap(NextArr[i],NextArr[Cell.second]);
                string NextKey=Encode(NextArr);
                ll NextCost=Cost+Cell.first;
                if(!Dist.count(NextKey) || Dist[NextKey]>NextCost)
                {
                    pq.push({NextCost,NextArr});
                    Dist[NextKey]=NextCost;
                }
            }
        }
    }
    cout<<-1;
}