#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;
int main()
{
    int N=0,M=0;
    cin>>N>>M;
    vector<vector<pair<int,int>>> Graph(N+1);
    while(M--)
    {
        int From,To,Cost;
        cin>>From>>To>>Cost;
        Graph[From].push_back({To,Cost});
    }
    int Start, Target;
    cin>>Start>>Target;
    vector<int> DP(N+1,INT_MAX);
    DP[Start]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,Start});
    while(!pq.empty())
    {
        int Dist=pq.top().first;
        int Cur=pq.top().second;
        pq.pop();
        if(DP[Cur]<Dist)
        {
            continue;
        }
        for(auto& Edge : Graph[Cur])
        {
            int NextCost=Edge.second;
            int Next=Edge.first;
            if(DP[Next]>DP[Cur]+NextCost)
            {
                DP[Next]=DP[Cur]+NextCost;
                pq.push({DP[Next],Next});
            }
        }
    }
    cout<<DP[Target];
}