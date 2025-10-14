#include <bits/stdc++.h>

using namespace std;
const int INF=1e9;
int main()
{
    int N=0;
    cin>>N;
    int Res=INT_MAX;
    vector<vector<int>> H(N,vector<int>(3,0));
    for(int i=0;i<N;++i)
    {
        cin>>H[i][0]>>H[i][1]>>H[i][2];
    }
    
    for(int S=0;S<3;++S)
    {
        vector<vector<int>> DP(N,vector<int>(3,INF));
        DP[0][S]=H[0][S];
        
        for(int i=1;i<N;++i)
        {
            DP[i][0]=H[i][0]+min(DP[i-1][1],DP[i-1][2]);
            DP[i][1]=H[i][1]+min(DP[i-1][0],DP[i-1][2]);
            DP[i][2]=H[i][2]+min(DP[i-1][1],DP[i-1][0]);
        }
        for(int E=0;E<3;++E)
        {
            if(E==S) continue;
            Res=min(Res,DP[N-1][E]);
        }
    }
    cout<<Res;
}