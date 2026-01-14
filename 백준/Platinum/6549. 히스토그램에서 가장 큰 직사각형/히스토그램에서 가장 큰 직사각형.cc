#include "bits/stdc++.h"
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(1)
    {
        int N;
        cin>>N;
        if(!N) break;
        
        vector<int> H(N+1,0);
        stack<int> St;
        ll Max=0;
        for(int i=0;i<N;++i) cin>>H[i];
        for(int i=0;i<=N;++i)
        {
            while(!St.empty() && H[St.top()] > H[i])
            {
                int Height=H[St.top()];
                St.pop();
                int Width= St.empty() ? i : i-St.top()-1; 
                // 스택의 탑을 기준으로 이전 탑의 바로 앞까지 포함하여 면적 계산
                // - (St.top()-1) ~ (i-1) 
                // -> i-1 - (St.top()+1) + 1 = i-St.top()-1
                Max=max(Max,1LL*Height*Width);
            }
            St.push(i);
        }
        cout<<Max<<'\n';
    }
}