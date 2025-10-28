#include <bits/stdc++.h>

using namespace std;

class UF
{
private:
    vector<int> P;
    
public:
    UF(int n)
    {
        P.resize(n);
        iota(P.begin(),P.end(),0);
    }
    int Find(int v)
    {
        if(P[v]==v)
        {
            return v;
        }
        return P[v]=Find(P[v]);
    }
    void Merge(int v1, int v2)
    {
        int r1=Find(v1);
        int r2=Find(v2);
        if(r1==r2) return;
        
        P[r2]=r1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N,M,K;
    cin>>N>>M>>K;
    vector<int> Cards(M,0);
    for(auto& c : Cards) cin>>c;
    sort(Cards.begin(),Cards.end());
    UF U(M+1);

    while(K--)
    {
        int Num=0;
        cin>>Num;
        int Idx=upper_bound(Cards.begin(),Cards.end(),Num)-Cards.begin();
        int Res=U.Find(Idx);
        cout<<Cards[Res]<<"\n";
        U.Merge(Res+1,Res);
    }
    
}