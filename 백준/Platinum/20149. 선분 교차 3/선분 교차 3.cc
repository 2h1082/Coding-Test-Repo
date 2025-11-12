#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
using ll=long long;
using P=pair<ll,ll>;

int CCW(P& A, P& B, P& C)
{
    ll Temp=(B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);
    if(Temp>0) return 1;
    else if(Temp<0) return -1;
    return 0;
}

void FindIntersection(P& A, P& B, P& C, P& D)
{
    double px=(A.x*B.y-A.y*B.x)*(C.x-D.x) - (A.x-B.x)*(C.x*D.y-C.y*D.x);
    double py=(A.x*B.y-A.y*B.x)*(C.y-D.y) - (A.y-B.y)*(C.x*D.y-C.y*D.x);
    double p = (A.x-B.x)*(C.y-D.y)-(A.y-B.y)*(C.x-D.x);
    
    if(p==0)
    {
        if(B==C&&A<=C) cout<<B.x<<' '<<B.y<<'\n';
        else if(A==D&&C<=A) cout<<A.x<<' '<<A.y<<'\n';
    }
    else
    {
        double ResX=px/p;
        double ResY=py/p;
        cout<<fixed<<setprecision(9)<<ResX<<' '<<ResY;
    }
}
void IsCross(P& A, P& B, P& C, P& D)
{
    ll Ans1=CCW(A,B,C)*CCW(A,B,D), Ans2=CCW(C,D,A)*CCW(C,D,B);
    
    if(Ans1==0&&Ans2==0)
    {
        if(A>B) swap(A,B);
        if(C>D) swap(C,D);
        if(A<=D&&B>=C)
        {
            cout<<1<<'\n';
            FindIntersection(A,B,C,D);
        }
        else cout<<0<<'\n';
    }
    else
    {
        if(Ans1<=0&&Ans2<=0)
        {
            cout<<1<<'\n';
            FindIntersection(A,B,C,D);
        }
        else cout<<0<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    P A, B, C, D;
    cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y>>D.x>>D.y;

    IsCross(A,B,C,D);
     
}