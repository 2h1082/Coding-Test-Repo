#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    
    vector<int> A(N,0);
    for(auto& a : A) cin>>a;
    
    unordered_map<int,int> Cnt;
    int R=0;
    ll Ans=0;
    for(int L=0;L<N;++L)
    {
        while(R<N && !Cnt[A[R]])
        {
            Cnt[A[R]]++;
            R++;
        }
        Ans+=R-L;
        Cnt[A[L]]--; //좌측 시작 좌표 범위 벗어나니 등장 횟수에서 차감
    }
    cout<<Ans;
}