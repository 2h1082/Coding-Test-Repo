#include <bits/stdc++.h>

using namespace std;
using Dot=pair<int,int>;

int CCW(Dot A, Dot B, Dot C)
{
    // AB, AC : {bx-ax, by-ay}, {cx-ax, cy-ay}
    long long Cross=1LL*(B.first-A.first)*(C.second-A.second)-1LL*(B.second-A.second)*(C.first-A.first);
    if(Cross>0) return 1;
    else if(Cross<0) return -1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N=0;
    cin>>N;
    
    vector<Dot> Point(N);
    for(auto& [p1,p2] : Point)
    {
        cin>>p1>>p2;
    }
    sort(Point.begin(),Point.end());
    
    vector<Dot> Upper, Lower;
    for(auto& p : Point)
    {
        while(Lower.size()>=2&&CCW(Lower[Lower.size()-2],Lower[Lower.size()-1],p)<=0) Lower.pop_back();
        Lower.push_back(p);
    }
    Lower.pop_back();
    for(int i=N-1;i>=0;--i)
    {
        while(Upper.size()>=2&&CCW(Upper[Upper.size()-2],Upper[Upper.size()-1],Point[i])<=0) Upper.pop_back();
        Upper.push_back(Point[i]);
    }
    Upper.pop_back();
    cout<<Lower.size()+Upper.size();
}