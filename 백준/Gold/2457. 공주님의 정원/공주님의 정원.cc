#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    
    vector<pair<int,int>> A(N);
    for(int i=0;i<N;++i)
    {
        int m1,d1,m2,d2;
        cin>>m1>>d1>>m2>>d2;
        A[i]={m1*100+d1, m2*100+d2};
    }
    sort(A.begin(),A.end());

    int Cnt=0, Target=301, Idx=0;
    while(Target <= 1130)
    {
        int MaxEnd=0;
        while(Idx < N && A[Idx].first <= Target)
        {
            MaxEnd=max(MaxEnd,A[Idx].second);
            ++Idx;
        }
        if(MaxEnd <= Target)
        {
            Cnt=0;
            break;
        }
        ++Cnt;
        Target=MaxEnd;
    }
    cout<<Cnt;
}