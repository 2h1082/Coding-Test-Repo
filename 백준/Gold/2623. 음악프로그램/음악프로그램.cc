#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,M;
    cin>>N>>M;
    vector<int> Degree(N+1,0);
    vector<vector<int>> Graph(N+1,vector<int>());
    queue<int> q;
    while(M--)
    {
        int Num=0;
        cin>>Num;
        vector<int> Temp(Num,0);
        for(auto& T : Temp)
        {
            cin>>T;
        }
        for(int i=0;i<Num-1;++i)
        {
            for(int j=i+1;j<Num;++j)
            {
                Graph[Temp[i]].push_back(Temp[j]);
                Degree[Temp[j]]++;
            }
        }
    }
    vector<int> Res;
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
        q.pop();
        Res.push_back(Cur);
        for(auto& Next : Graph[Cur])
        {
            Degree[Next]--;
            if(!Degree[Next])
            {
                q.push(Next);
            }
        }
    }
    if(Res.size()!=N)
    {
        cout<<"0";
    }
    else
    {
        for(auto& R : Res)
        {
            cout<<R<<"\n";
        }
    }
}