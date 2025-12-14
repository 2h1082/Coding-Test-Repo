#include "bits/stdc++.h"
using namespace std;

struct UF
{
    vector<int> Parent;
    vector<int> Size;
    
    UF(int n)
    {
        Parent.assign(n+1,0);
        Size.assign(n+1,0);
        iota(Parent.begin(),Parent.end(),0);
    }
    int Find(int v)
    {
        if(v==Parent[v]) return v;
        
        return Parent[v]=Find(Parent[v]);
    }
    void Merge(int v1, int v2)
    {
        int r1=Find(v1), r2=Find(v2);
        
        if(r1==r2) return;
        
        if(Size[r1]<Size[r2])
        {
            swap(r1,r2);
        }
        Parent[r2]=r1;
        Size[r1]+=Size[r2];
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M;
    cin>>N>>M;
    
    UF U(N);
    for(int i=1;i<=N;++i)
    {
        for(int j=1;j<=N;++j)
        {
            int Num;
            cin>>Num;
            if(Num) U.Merge(i,j);
        }
    }
    int v;
    cin>>v;
    v=U.Find(v);
    for(int i=1;i<M;++i)
    {
        int Num;
        cin>>Num;
        if(v!=U.Find(Num))
        {
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
}