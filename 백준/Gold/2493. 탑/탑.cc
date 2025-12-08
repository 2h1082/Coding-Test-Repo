#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    
    vector<int> T(N,0);
    stack<pair<int,int>> st;
    for(int i=0;i<N;++i)
    {
        cin>>T[i];
        
        while(!st.empty() && st.top().first <= T[i]) st.pop();
        
        if(!st.empty()) cout<<st.top().second<<' ';
        else            cout<<0<<' ';
        st.push({T[i],i+1});
    }
    
    
}