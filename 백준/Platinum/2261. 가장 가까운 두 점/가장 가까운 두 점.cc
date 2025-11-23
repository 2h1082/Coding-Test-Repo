#include "bits/stdc++.h"
using namespace std;
using P=pair<int,int>;
using ll=long long;
#define y second
#define x first
vector<P> Dot, Tmp;

bool CmpY(const P& a, const P& b)
{
    return a.y < b.y;
}
ll Dist(const P& a, const P& b)
{
    ll Dx=(ll)b.x-a.x;
    ll Dy=(ll)b.y-a.y;
    return Dx*Dx + Dy*Dy;
}
ll Solve(int L, int R)
{
    int n=R-L+1;
    if(n<=3)
    {
        ll D=LLONG_MAX;
        for(int i=L;i<=R;++i)
        {
            for(int j=i+1;j<=R;++j)
            {
                D=min(D,Dist(Dot[i],Dot[j]));
            }
        }
        return D;
    }
    
    int Mid=(L+R)/2;
    int MidX=Dot[Mid].x;
    ll D=min(Solve(L,Mid),Solve(Mid+1,R));
    
    Tmp.clear();
    for(int i=L;i<=R;++i) Tmp.push_back(Dot[i]);
    
    sort(Tmp.begin(),Tmp.end(),CmpY);
    
    vector<P> Strip;
    Strip.reserve(n);
    for(auto& p : Tmp)
    {
        if((ll)(p.x-MidX)*(p.x-MidX) < D) Strip.push_back(p);
    }
    
    for(int i=0;i<Strip.size();++i)
    {
        for(int j=i+1;j<Strip.size(); ++j)
        {   
            if(((ll)Strip[j].y-Strip[i].y) * ((ll)Strip[j].y-Strip[i].y) >= D) break;
            D=min(D,Dist(Strip[i],Strip[j]));
        }
    }
    return D;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N=0;
    cin>>N;
    
    Dot.assign(N,{});
    Tmp.reserve(N);
    for(auto& d : Dot) cin>>d.x>>d.y;
    
    sort(Dot.begin(),Dot.end());
    
    cout<<Solve(0,N-1);
}