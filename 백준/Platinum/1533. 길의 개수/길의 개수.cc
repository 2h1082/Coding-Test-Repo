#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<vector<ll>> Adj;
int Mod=1000003;
    
vector<vector<ll>> MatMul(const vector<vector<ll>>& A, const vector<vector<ll>>& B)
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
        if(Exp&1) Res=MatMul(Res,Base);
        Base=MatMul(Base,Base);
        Exp>>=1;
    }
    return Res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,S,E,T;
    cin>>N>>S>>E>>T;
    --S; --E;
    
    Adj.assign(5*N,vector<ll>(5*N));
    for(int v=0;v<N;++v)
    {
        for(int t=1;t<5;++t)
        {
            Adj[v*5+t][v*5+(t-1)]=1;
        }
    }
    
    for(int i=0;i<N;++i)
    {
        string In;
        cin>>In;
        for(int j=0;j<N;++j)
        {
            int W=In[j]-'0';
            if(W==0) continue;
            Adj[i*5][j*5+(W-1)]=(Adj[i*5][j*5+(W-1)]+1)%Mod;
        }
    }
    Adj=MatPow(Adj,T);
    cout<<Adj[S*5][E*5];
}