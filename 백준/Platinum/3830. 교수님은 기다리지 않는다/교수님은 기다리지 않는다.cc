#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct UF
{
    vector<int> Parent;
    vector<ll> Dist;
    vector<int> Size;
    UF(int n)
    {
        Parent.assign(n+1,0);
        iota(Parent.begin(),Parent.end(),0);
        Dist.assign(n+1,0);
        Size.assign(n+1,1);
    }
    int Find(int v)
    {
        if(v==Parent[v]) return v;
        
        int ParentV=Parent[v];
        int Root=Find(ParentV);
        Dist[v]+=Dist[ParentV];
        return Parent[v]=Root;
    }
    void Union(int A, int B, int w)
    {
        int RootA=Find(A), RootB=Find(B);
        if(RootA==RootB) return;
        
        if(Size[RootA]>Size[RootB])
        {
            swap(A,B);
            swap(RootA,RootB);
            w=-w;
        }
        Parent[RootA]=RootB;
        Dist[RootA]=Dist[B]-Dist[A]-w;
        Size[RootB]+=Size[RootA];
    }
    ll GetWeightGap(int A, int B)
    {
        return Dist[B]-Dist[A];
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,M;
    while(cin>>N>>M)
    {
        if(!N&&!M) break;
        
        UF u(N);
        while(M--)
        {
            char Com;
            cin>>Com;
            if(Com=='?')
            {
                int a,b;
                cin>>a>>b;
                if(u.Find(a)==u.Find(b))
                    cout<<u.GetWeightGap(a,b)<<'\n';
                else
                    cout<<"UNKNOWN\n";
            }
            else if(Com=='!')
            {
                int a,b,w;
                cin>>a>>b>>w;
                u.Union(a,b,w);
            }
        }
    }
}