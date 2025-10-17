#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N=0,M=0;
    cin>>N>>M;
    vector<int> Rank(N+1);
    vector<vector<int>> Graph(N+1);
    while(M--)
    {
        int Prev, Next;
        cin>>Prev>>Next;
        Graph[Prev].push_back(Next);
        Rank[Next]++;
    }
    priority_queue<int,vector<int>,greater<>> q;
    for(int i=1;i<=N;++i)
    {
        if(!Rank[i]) q.push(i);
    }
    while(!q.empty())
    {
        int Cur=q.top();
        cout<<Cur<<" ";
        q.pop();
        for(auto& Next : Graph[Cur])
        {
            --Rank[Next];
            if(!Rank[Next])
            {
                q.push(Next);
            }
        }
    }
}