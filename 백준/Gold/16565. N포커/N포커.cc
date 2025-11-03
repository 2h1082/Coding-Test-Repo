#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N=0, Mod=10007;
    cin>>N;
    int Comb[53][53];
    
    for(int n=0;n<53;++n)
    {
        Comb[n][0]=Comb[n][n]=1;
        for(int r=1;r<n;++r)
        {
            Comb[n][r]=(Comb[n-1][r]+Comb[n-1][r-1])%Mod;
        }
    }
    int Ans=0;
    for(int k=1;k<=N/4;++k)
    {
        int Cnt=(Comb[13][k]*Comb[52-4*k][N-4*k])%Mod;
        if(k%2)    Ans=(Ans+Cnt)%Mod;
        else       Ans=(Ans-Cnt+Mod)%Mod;
    }
    cout<<Ans;
}