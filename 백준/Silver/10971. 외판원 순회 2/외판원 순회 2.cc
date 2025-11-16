#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N=0;
    cin>>N;
    vector<vector<int>> Adj(N,vector<int>(N,0));
    for(auto& r : Adj)
        for(auto& c : r)
            cin>>c;
    int MaxBit=(1<<N);
    int Res=INT_MAX;
    for(int S=0;S<N;++S)
    {
        vector<vector<int>> Dp(MaxBit,vector<int>(N,1e9));
        Dp[1<<S][S]=0;
        for(int Mask=0;Mask<MaxBit;++Mask)
        {
            for(int Cur=0;Cur<N;++Cur)
            {
                if(!(Mask&(1<<Cur))) continue;
                for(int Nxt=0;Nxt<N;++Nxt)
                {
                    if(Nxt==Cur || Mask&(1<<Nxt) || !Adj[Cur][Nxt]) continue;
                    int Nmask=Mask|(1<<Nxt);
                    Dp[Nmask][Nxt]=min(Dp[Nmask][Nxt],Dp[Mask][Cur]+Adj[Cur][Nxt]);
                }                
            }            
        }
        int FullMask=(1<<N)-1;
        for(int E=0;E<N;++E)
        {
            if(E==S || !Adj[E][S]) continue;
            Res=min(Res,Adj[E][S]+Dp[FullMask][E]);
        }
    }
    cout<<Res;
}