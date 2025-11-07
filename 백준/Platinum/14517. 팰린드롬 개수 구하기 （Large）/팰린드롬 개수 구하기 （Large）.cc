#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int N=s.size(), Mod=10007;
    vector<vector<int>> DP(N,vector<int>(N,0));
    
    for(int i=0;i<s.size();++i)
    {
        DP[i][i]=1;
    }
    for(int Len=2;Len<=N;++Len)
    {
        for(int i=0;i<N-Len+1;++i)
        {
            int j=i+Len-1;
            DP[i][j]=DP[i+1][j]+DP[i][j-1]-DP[i+1][j-1];
            if(s[i]==s[j])
            {
                DP[i][j]+=DP[i+1][j-1]+1;
            }
            DP[i][j]=(DP[i][j]%Mod+Mod)%Mod;
        }
    }
    cout<<DP[0][N-1];
}