#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin>>T;
    while(T--)
    {
        string W;
        int K;
        cin>>W>>K;
        
        vector<vector<int>> Pos(26);
        for(int i=0;i<W.size();++i) Pos[W[i]-'a'].push_back(i);
        
        int Min=1e9, Max=0;
        
        for(int c=0;c<26;++c)
        {
            auto& V=Pos[c];
            if(V.size() < K) continue;
            
            for(int i=0;i+K-1<V.size();++i)
            {
                int L=V[i], R=V[i+K-1];
                int Len=R-L+1;
                
                Min=min(Min,Len);
                Max=max(Max,Len);
            }
        }
        if(Max==0 || Min==1e9) cout<<-1;
        else                   cout<<Min<<' '<<Max;
        cout<<'\n';
    }
}