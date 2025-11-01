#include <bits/stdc++.h>

using namespace std;
using ll=long long;
int N=0;
vector<int> Nums;
int main()
{
    while(1)
    {
        cin>>N;
        if(!N) break;
        Nums.assign(N+1,0);
        for(int i=0;i<N;++i)
        {
            cin>>Nums[i];
        }
        Nums[N]=0;
        stack<int> st;
        ll MaxArea=0;
        for(int i=0;i<=N;++i)
        {
            while(!st.empty()&&Nums[st.top()]>Nums[i])
            {
                int Height=Nums[st.top()];
                st.pop();
                int Width= st.empty() ? i : (i-st.top()-1);
                MaxArea=max(MaxArea,1LL*Height*Width);
            }
            st.push(i);
        }
        cout<<MaxArea<<"\n";
    }
}