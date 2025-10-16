#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T=0, N=0;
    cin>>T>>N;
    vector<int> A(N,0);
    for(auto& a : A)
    {
        cin>>a;
    }
    vector<int> Sums;
    for(int i=0;i<N;++i)
    {
        int Sum=0;
        for(int j=i;j<N;++j)
        {
            Sum+=A[j];
            Sums.push_back(Sum);
        }
    }
    sort(Sums.begin(),Sums.end());
    int M=0;
    cin>>M;
    vector<int> B(M,0);
    for(auto& b : B)
    {
        cin>>b;
    }
    long long Cnt=0;
    for(int i=0;i<M;++i)
    {
        int Sum=0;
        for(int j=i;j<M;++j)
        {
            Sum+=B[j];
            int Target=T-Sum;
            auto S=lower_bound(Sums.begin(),Sums.end(),Target);
            auto E=upper_bound(Sums.begin(),Sums.end(),Target);
            Cnt+=E-S;
        }
    }
    cout<<Cnt;
}