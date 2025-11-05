#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N=0;
    cin>>N;
    vector<int> Num(N,0);
    for(auto& n : Num)
    {
        cin>>n;
    }
    stack<pair<int,int>> st;
    long long Cnt=0;
    for(auto& n : Num)
    {
        int Same=1;
        while(!st.empty()&&st.top().first<=n)
        {
            Cnt+=st.top().second;
            if(st.top().first==n) Same+=st.top().second;
            st.pop();
        }
        if(!st.empty()) Cnt++;
        st.push({n,Same});
    }
    cout<<Cnt;
}