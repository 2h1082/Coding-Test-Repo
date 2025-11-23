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
        sort(Dot.begin()+L,Dot.begin()+R+1,CmpY);
        return D;
    }
    
    int Mid=(L+R)/2;
    int MidX=Dot[Mid].x;
    ll D=min(Solve(L,Mid),Solve(Mid+1,R));
    
    merge(Dot.begin()+L,Dot.begin()+Mid+1,Dot.begin()+Mid+1,Dot.begin()+R+1,Tmp.begin(),CmpY);
    copy(Tmp.begin(),Tmp.begin()+n,Dot.begin()+L);
    
    vector<P> Strip;
    Strip.reserve(n);
    for(int i=L;i<=R;++i)
    {
        if((ll)(Dot[i].x-MidX)*(Dot[i].x-MidX) < D) Strip.push_back(Dot[i]);
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