#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    vector<int> A(N,0);
    for(auto& a : A) cin>>a;
    
    vector<int> Cnt(N,0), Ans(N,-1);
    
    stack<int> LeftSt, RightSt;
    
    // 좌 ~ 우
    for(int i=0;i<N;++i)
    {
        while(!LeftSt.empty() && A[LeftSt.top()] <= A[i]) LeftSt.pop();
        
        Cnt[i]+=LeftSt.size();
        if(!LeftSt.empty()) Ans[i]=LeftSt.top();
        LeftSt.push(i);
    }
    // 우 ~ 좌
    for(int i=N-1;i>=0;--i)
    {
        while(!RightSt.empty() && A[RightSt.top()] <= A[i]) RightSt.pop();
        
        Cnt[i]+=RightSt.size();
        if(!RightSt.empty())
        {
            if(Ans[i]==-1) Ans[i]=RightSt.top();
            else
            {
                int DistL=i-Ans[i], DistR=RightSt.top()-i;
                if(DistL > DistR) Ans[i]=RightSt.top();
            }
        }
        RightSt.push(i);
    }
    
    for(int i=0;i<N;++i)
    {
        cout<<Cnt[i]<<' ';
        if(Ans[i]==-1) continue;
        
        cout<<Ans[i]+1<<'\n';
    }
}