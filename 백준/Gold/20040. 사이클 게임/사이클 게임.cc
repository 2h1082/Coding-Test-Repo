#include <bits/stdc++.h>

using namespace std;
class Union
{
private:
    vector<int> P;
    vector<int> Size;
public:
    Union(int N)
    {
        P.resize(N);
        iota(P.begin(),P.end(),0);
        Size.assign(N,1);
    }
    int Find(int u)
    {
        if(P[u]==u)
        {
            return u;
        }
        return P[u]=Find(P[u]);
    }
    bool Merge(int u, int v)
    {
        u=Find(u);
        v=Find(v);
        
        if(u==v) return false;
        
        if(Size[u]<Size[v])
        {
            swap(u,v);
        }
        P[v]=u;
        Size[u]+=Size[v];
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N=0, M=0;
    cin>>N>>M;
    Union U(N);
    for(int i=1;i<=M;++i)
    {
        int F, T;
        cin>>F>>T;
        if(!U.Merge(F,T))
        {
            cout<<i;
            return 0;
        }
    }
    cout<<"0";
    return 0;
}