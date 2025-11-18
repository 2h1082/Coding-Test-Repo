#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
    ios::sync_with_stdio(false);
    
    int N=0;
    cin>>N;
    vector<int> Num(N+1,0);
    for(int i=0;i<N;++i) cin>>Num[i];
    
    stack<int> st;
    ll Res=0;
    for(int i=0;i<=N;++i)
    {
        while(!st.empty() && Num[st.top()]>Num[i])
        {
            int H=Num[st.top()];
            st.pop();
            int W=st.empty() ? i : i-1-st.top();
            Res=max(Res,1LL*H*W);
        }
        st.push(i);
    }
    cout<<Res;
}