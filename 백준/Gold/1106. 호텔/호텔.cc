#include <bits/stdc++.h>

using namespace std;

int main()
{
    int C=0,N=0;
    cin>>C>>N;
    vector<pair<int,int>> Info(N);
    vector<int> DP(3001,INT_MAX);
    for(auto& I : Info)
    {
        cin>>I.first>>I.second;
    }
    DP[0]=0;
    for (auto& I : Info)
    {
        int Cost=I.first, Count=I.second;
        for (int i=Count;i<=3000;++i)
        {
            if (DP[i-Count]!=INT_MAX)
            {
                DP[i]=min(DP[i],DP[i-Count]+Cost);
            }
        }
    }
    cout<<*min_element(next(DP.begin(),C),DP.end());
}