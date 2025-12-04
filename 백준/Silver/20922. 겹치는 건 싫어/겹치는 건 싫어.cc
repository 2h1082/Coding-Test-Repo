#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,K;
    cin>>N>>K;
    vector<int> Num(N);
    for(auto& n : Num) cin>>n;
    
    vector<int> Cnt(100001,0);
    int L=0, Ans=0;
    for(int R=0;R<N;++R)
    {
        Cnt[Num[R]]++;
        
        while(Cnt[Num[R]]>K)
        {
            Cnt[Num[L]]--;
            L++;
        }
        Ans=max(Ans,R-L+1);
    }
    cout<<Ans;
}
