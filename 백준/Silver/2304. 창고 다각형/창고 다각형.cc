#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    
    vector<pair<int,int>> B(N);
    for(auto& p : B) cin>>p.first>>p.second;
    
    sort(B.begin(),B.end());
    int MaxIdx=0, MaxH=0;
    for(int i=0;i<N;++i)
    {
        if(B[i].second > MaxH) 
        { 
            MaxIdx=i;
            MaxH=B[i].second;
        }
    }
    
    int Area=0;
    int LeftMax=B[0].second, LeftW=B[0].first;    
    for(int i=1;i<=MaxIdx;++i)
    {
        if(LeftMax <= B[i].second)
        {
            Area+=LeftMax * (B[i].first - LeftW);
            LeftW=B[i].first;
            LeftMax=B[i].second;
        }
    }
    int RightMax=B[N-1].second, RightW=B[N-1].first;    
    for(int i=N-2;i>=MaxIdx;--i)
    {
        if(RightMax <= B[i].second)
        {
            Area+=RightMax * (RightW - B[i].first);
            RightW=B[i].first;
            RightMax=B[i].second;
        }
    }
    Area+=MaxH;
    cout<<Area;
}
