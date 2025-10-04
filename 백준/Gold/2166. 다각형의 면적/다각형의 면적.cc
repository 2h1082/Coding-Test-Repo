#include <bits/stdc++.h>

using namespace std;
int main()
{
    int N=0;
    cin>>N;
    vector<pair<long long,long long>> Dots(N);
    pair<double, double> Center={0,0};
    for(auto& P : Dots)
    {
        long long x,y;
        cin>>x>>y;
        P={y,x};
        Center.first+=y;
        Center.second+=x;        
    }
    Center.first/=N;
    Center.second/=N;
    
    long long Sum1=0,Sum2=0;
    for (int i=0;i<N;++i)
    {
        int NextIdx=(i+1)%N;
        Sum2+=Dots[i].first*Dots[NextIdx].second;
        Sum1+=Dots[i].second*Dots[NextIdx].first;
    }
    double Area=0.5*abs(Sum1-Sum2);
    cout<<fixed<<setprecision(1)<<Area;
}