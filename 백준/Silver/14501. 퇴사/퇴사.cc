#include <bits/stdc++.h>
using namespace std;
#define t first
#define p second
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N=0;
    cin>>N;
    vector<pair<int,int>> Info(N+1,{0,0});
    for(int i=1;i<=N;++i) cin>>Info[i].t>>Info[i].p;
    vector<int> DP(N+1,0);
    for(int i=1;i<=N;++i)
    {
        DP[i]=max(DP[i],DP[i-1]);
        int End=i+Info[i].t-1;
        if(End<=N) DP[End]=max(DP[End],DP[i-1]+Info[i].p);
    }
    cout<<DP[N];
}