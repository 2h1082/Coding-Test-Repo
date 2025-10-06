#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,M;
    cin>>N>>M;
    vector<vector<int>> S(N+1,vector<int>());
    
    vector<int> Degree(N+1,0);
    while(M--)
    {
        int Front, Back;
        cin>>Front>>Back;
        S[Front].push_back(Back);
        Degree[Back]++;
    }
    queue<int> q;
    for(int i=1;i<=N;++i)
    {
        if(!Degree[i])
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int Cur=q.front();
        cout<<Cur<<" ";
        q.pop();
        for(auto& Next:S[Cur])
        {
            Degree[Next]--;
            if(!Degree[Next]) q.push(Next);
        }
    }
}