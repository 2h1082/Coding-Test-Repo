#include "bits/stdc++.h"
using namespace std;

struct Info
{
    int Cnt, a,b,c,d;
};
int main()
{
    // 1, 5, 10, 25
    int X, A, B, C, D;
    cin>>X>>A>>B>>C>>D;
    
    vector<Info> Dp(X+1,{-1,0,0,0,0});
    Dp[0]={0,0,0,0,0};
    
    const int V[4]={1,5,10,25};
    
    for(int i=1;i<=X;++i)
    {
        for(int j=0;j<4;++j)
        {
            int Coin=V[j];
            if(i-Coin<0) continue;
            if(Dp[i-Coin].Cnt==-1) continue;
            
            Info Prev=Dp[i-Coin];
            int Na=Prev.a, Nb=Prev.b, Nc=Prev.c, Nd=Prev.d;
            
            if(j==0)      Na++;
            else if(j==1) Nb++;
            else if(j==2) Nc++;
            else if(j==3) Nd++;
            
            if(Na>A || Nb>B || Nc>C || Nd>D) continue;
            
            int NewCnt=Prev.Cnt+1;
            if(NewCnt>Dp[i].Cnt) Dp[i]={NewCnt,Na,Nb,Nc,Nd};
        }
    }
    
    if(Dp[X].Cnt == -1) cout<<"0 0 0 0\n";
    else                cout<<Dp[X].a<<' '<<Dp[X].b<<' '<<Dp[X].c<<' '<<Dp[X].d<<'\n';
}