#include <bits/stdc++.h>

using namespace std;
int N=0, M=0;
vector<vector<pair<int,int>>> Bus;
int main()
{
    cin>>N>>M;
    Bus.assign(N+1,vector<pair<int,int>>());
    while(M--)
    {
        int From,To,Cost;
        cin>>From>>To>>Cost;
        Bus[From].push_back({Cost,To});
    }
    int Start, End;
    cin>>Start>>End;
    priority_queue<pair<long long,int>> pq;
    pq.push({0,Start});
    vector<long long> DP(N+1,LLONG_MAX);
    vector<int> Visited(N+1,0);
    DP[Start]=0;
    while(!pq.empty())
    {
        int Cur=pq.top().second;
        long long CurCost=-pq.top().first;
        pq.pop();
        if(CurCost>DP[Cur]) continue;
        if(Cur==End) break;
        for(auto& Info:Bus[Cur])
        {
            int Next=Info.second;
            long long NextCost=Info.first+CurCost;
            if(NextCost<DP[Next])
            {
                DP[Next]=NextCost;
                pq.push({-NextCost,Next});
                Visited[Next]=Cur;
            }
        }
    }
    vector<int> Result;
    for(int Cur=End;Cur!=0;Cur=Visited[Cur])
    {
        Result.push_back(Cur);
    }
    cout<<DP[End]<<"\n"<<Result.size()<<"\n";
    
    for(int i=Result.size()-1;i>=0;--i)
    {
        cout<<Result[i]<<" ";
    }
}