#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int Mod=1000000007;
vector<vector<ll>> Mul(vector<vector<ll>>& A, vector<vector<ll>>& B)
{
    int N=A.size();
    vector<vector<ll>> Res(N,vector<ll>(N,0));
    for(int i=0;i<N;++i)
    {
        for(int k=0;k<N;++k)
        {
            if(!A[i][k]) continue;
            for(int j=0;j<N;++j)
            {
                if(!B[k][j]) continue;
                Res[i][j]=(Res[i][j]+A[i][k]*B[k][j])%Mod;
            }
        }
    }
    return Res;
}
vector<vector<ll>> MatPow(vector<vector<ll>> Base, int Exp)
{
    int N=Base.size();
    vector<vector<ll>> Res(N,vector<ll>(N,0));
    for(int i=0;i<N;++i) Res[i][i]=1;
    
    while(Exp>0)
    {
        if(Exp&1) Res=Mul(Res,Base);
        Base=Mul(Base,Base);
        Exp>>=1;
    }
    return Res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T,N,D;
    cin>>T>>N>>D;
    vector<vector<vector<ll>>> Map(T,vector<vector<ll>>(N,vector<ll>(N,0)));
    for(auto& m : Map)
    {
        int E=0;
        cin>>E;
        while(E--)
        {
            int a,b,c;
            cin>>a>>b>>c;
            --a; --b;
            m[a][b]=c;
        }
    }
    int Cycle=D/T, Remain=D%T;
    vector<vector<ll>> Res(N,vector<ll>(N,0));
    for(int i=0;i<N;++i) Res[i][i]=1;
    for(int t=0;t<T;++t) Res=Mul(Res,Map[t]);
    
    Res=MatPow(Res,Cycle);
    for(int t=0;t<(D%T);++t) Res=Mul(Res,Map[t]);
    
    for(auto& r: Res)
    {
        for(auto& c : r)
        {
            cout<<c<<" ";
        }
        cout<<'\n';
    }
}