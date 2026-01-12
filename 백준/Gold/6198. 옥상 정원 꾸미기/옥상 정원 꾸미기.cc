#include "bits/stdc++.h"
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    
    stack<int> St;
    ll Cnt=0;
    for(int i=0;i<N;++i)
    {
        int H;
        cin>>H;
        // 현재 높이 초과인 탑들만 스택에 보존
        // - 현재 스택에 넣는 탑을 볼 수 있는 빌딩만 스택에 남음
        while(!St.empty() && St.top() <= H) St.pop();
        Cnt+=St.size();
        
        St.push(H);
    }
    cout<<Cnt;
}