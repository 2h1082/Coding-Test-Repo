#include <bits/stdc++.h>

using namespace std;

vector<int> Nums;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N=0;
    cin>>N;
    Nums.assign(N,0);
    for(auto& Num : Nums)
    {
        cin>>Num;
    }
    vector<vector<int>> DP(N,vector<int>(N,0));
    for(int i=0;i<N;++i)
    {
        DP[i][i]=1;
    }
    for(int i=0;i<N-1;++i)
    {
        if(Nums[i]==Nums[i+1])
        {
            DP[i][i+1]=1;
        }
    }
    for(int L=3;L<=N;++L)
    {
        for(int i=0;i<=N-L;++i)
        {
            int j=i+L-1;
            if(Nums[i]==Nums[j]&&DP[i+1][j-1]==1) DP[i][j]=1;
        }
    }
    int M=0;
    cin>>M;
    while(M--)
    {
        int S=0,E=0;
        cin>>S>>E;
        cout<<DP[S-1][E-1]<<"\n";
    }
}