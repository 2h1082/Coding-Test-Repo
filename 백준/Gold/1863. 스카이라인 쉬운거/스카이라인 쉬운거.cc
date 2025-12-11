#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    
    vector<pair<int,int>> B(N);
    for(auto& b : B) cin>>b.first>>b.second;
    B.push_back({1000001,0});
    
    int Ans=0;
    stack<int> st;
    for(int i=0;i<N+1;++i)
    {
        while(!st.empty() && st.top() >= B[i].second)
        {
            if(st.top()>B[i].second) Ans++;
            st.pop();
        }
        st.push(B[i].second);
    }
    cout<<Ans;
}