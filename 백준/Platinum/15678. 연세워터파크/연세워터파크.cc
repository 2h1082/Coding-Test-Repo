#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N=0, D=0;
    cin>>N>>D;
    vector<ll> Bridge(N+1,0), DP(N+1);
    for(int i=1;i<=N;++i)
    {
        cin>>Bridge[i];
    }
    
    deque<int> dq;
    ll Ans=LLONG_MIN;
    for(int i=1;i<=N;++i)
    {
        while(!dq.empty()&&dq.front()<i-D) dq.pop_front();
        
        if(!dq.empty())
        {
            DP[i]=Bridge[i]+max(0LL,DP[dq.front()]);
        }
        else
        {
            DP[i]=Bridge[i];
        }
        while(!dq.empty()&&DP[dq.back()]<=DP[i]) dq.pop_back();
        dq.push_back(i);
        Ans=max(Ans,DP[i]);
    }
    cout<<Ans;
}