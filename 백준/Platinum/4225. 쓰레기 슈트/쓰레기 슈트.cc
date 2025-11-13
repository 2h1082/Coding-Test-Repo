#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
using P=pair<int,int>;
using ll=long long;

int CCW(P& A, P& B, P& C)
{
    ll Temp=1LL*(B.x-A.x)*(C.y-A.y) - 1LL*(B.y-A.y)*(C.x-A.x);
    if(Temp>0) return 1;
    if(Temp<0) return -1;
    return 0;
}
double Cross(P& A, P& B)
{
    return A.x*B.y - A.y*B.x;
}
P Sub(P& A, P& B)
{
    return {A.x-B.x,A.y-B.y};
}
double DistPointToLine(P& A, P& B, P& Dot)
{
    P v=Sub(B,A), w=Sub(Dot,A);
    double Area=fabs(Cross(v,w));
    double Base=hypot(v.x,v.y);
    return Area/Base;
}
double MinWidth(vector<P>& H)
{
    int M=H.size();
    double Ans=1e18;
    int j=1;
    for(int i=0;i<M;++i)
    {
        int NxtI=(i+1)%M;
        while(1)
        {
            int NxtJ=(j+1)%M;
            double Cur=DistPointToLine(H[i],H[NxtI],H[j]);
            double Nxt=DistPointToLine(H[i],H[NxtI],H[NxtJ]);
            if(Nxt>Cur) j=NxtJ;
            else        break;
        }
        Ans=min(Ans,DistPointToLine(H[i],H[NxtI],H[j]));
    }
    return Ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N=0;
    int Cnt=1;
    while(cin>>N)
    {
        if(!N) break;
        
        vector<P> Pts(N);
        for(auto& [X,Y]:Pts) cin>>X>>Y;
        
        sort(Pts.begin(),Pts.end());
        vector<P> Up, Low;
        for(int i=0;i<N;++i)
        {
            while(Low.size()>=2&&CCW(Low[Low.size()-2],Low.back(),Pts[i])<=0)
                Low.pop_back();
            Low.push_back(Pts[i]);
        }
        Low.pop_back();
        for(int i=N-1;i>=0;--i)
        {
            while(Up.size()>=2&&CCW(Up[Up.size()-2],Up.back(),Pts[i])<=0)
                Up.pop_back();
            Up.push_back(Pts[i]);
        }
        Up.pop_back();
        vector<P> Hull=Low;
        Hull.insert(Hull.end(),Up.begin(),Up.end());
        
        double Ans=MinWidth(Hull);
        Ans=ceil(Ans*100.0)/100.0;
        cout<<"Case "<<Cnt<<": ";
        cout<<fixed<<setprecision(2)<<Ans<<'\n';
        ++Cnt;
    }
}