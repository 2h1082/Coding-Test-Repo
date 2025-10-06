#include <bits/stdc++.h>

using namespace std;
int main()
{
    int T=0;
    cin>>T;
    while(T--)
    {
        int N,K;
        cin>>N>>K;
        vector<long long> Delay(N+1,0);
        vector<vector<int>> Graph(N+1,vector<int>());
        for(int i=1;i<=N;++i)
        {
            cin>>Delay[i];
        }
        vector<int> Degree(N+1,0);
        while(K--)
        {
            int Prev, Next;
            cin>>Prev>>Next;
            Graph[Prev].push_back(Next);
            Degree[Next]++;
        }
        vector<long long> DP(N+1,0);
        queue<int> q;
        for(int i=1;i<=N;++i)
        {
            if(Degree[i]==0)
            {
                q.push(i);
                DP[i]=Delay[i];
            }
        }
        while(!q.empty())
        {
            int Cur=q.front();
            q.pop();
            for(auto& Next : Graph[Cur])
            {
                DP[Next]=max(DP[Next],DP[Cur]+Delay[Next]);
                Degree[Next]--;
                if(!Degree[Next])
                {
                    q.push(Next);
                }
            }
        }
        int W=0;
        cin>>W;
        cout<<DP[W]<<"\n";
    }
}