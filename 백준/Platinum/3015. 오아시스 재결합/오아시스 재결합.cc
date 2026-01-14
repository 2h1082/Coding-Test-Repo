#include "bits/stdc++.h"
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    
    stack<pair<int,int>> St;
    ll Cnt=0;
    while(N--)
    {
        int H, Same=1;
        cin>>H;
        while(!St.empty() && St.top().first <= H)
        {
            Cnt+=St.top().second;
            if(St.top().first==H) Same+=St.top().second;
            St.pop();
        }
        if(!St.empty()) ++Cnt;
        St.push({H,Same});
    }
    cout<<Cnt;
}