#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N=0;
    cin>>N;
    vector<long long> A(N), B(N), C(N), D(N);
    for(int i=0;i<N;++i)
    {
        cin>>A[i]>>B[i]>>C[i]>>D[i];
    }
    vector<long long> SumAB;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            SumAB.push_back(A[i]+B[j]);
        }
    }
    sort(SumAB.begin(),SumAB.end());
    long long Res=0;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            long long Target=-(C[i]+D[j]);
            auto Start=lower_bound(SumAB.begin(),SumAB.end(),Target);
            auto End=upper_bound(SumAB.begin(),SumAB.end(),Target);
            Res+=(End-Start);
        }
    }
    cout<<Res;
}