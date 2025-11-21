#include "bits/stdc++.h"
using namespace std;

struct UF
{
    vector<int> Parent;
    vector<int> Size;
    
    UF(int n)
    {
        Parent.assign(n+1,0);
        iota(Parent.begin(),Parent.end(),0);
        Size.assign(n+1,1);
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
        
        if(Size[r1]<Size[r2]) swap(r1,r2);
        Parent[r2]=r1;
        Size[r1]+=r2;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    
    UF u(n);
    
    while(m--)
    {
        int c,a,b;
        cin>>c>>a>>b;
        if(c==0)
        {
            u.Merge(a,b);
        }
        else if(c==1)
        {
            if(u.Find(a)==u.Find(b)) cout<<"YES"<<'\n';
            else                     cout<<"NO"<<'\n';
        }
    }
}