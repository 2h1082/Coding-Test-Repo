#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M;
    cin>>N>>M;
    
    set<string> W;
    for(int i=0;i<N;++i)
    {
        string S;
        cin>>S;
        W.insert(S);
    }
    while(M--)
    {
        string S;
        cin>>S;
        
        stringstream ss(S);
        
        string Words;
        while(getline(ss,Words,','))
        {
            if(W.find(Words)!=W.end())
            {
                W.erase(Words);
            }
        }
        cout<<W.size()<<'\n';
    }
    
}