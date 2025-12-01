#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,K;
    string S;
    cin>>N>>K>>S;
    
    vector<int> P, H;
    
    for(int i=0;i<N;++i)
    {
        if(S[i]=='P') P.push_back(i);
        else if(S[i]=='H') H.push_back(i);
    }
    
    int i=0, j=0, Ans=0;
    while(i<P.size() && j<H.size())
    {
        int p=P[i];
        int h=H[j];
        
        if(abs(p-h)<=K)
        {
            ++Ans;
            ++i;
            ++j;
        }
        else if(h<p)
        {
            ++j;
        }
        else
        {
            ++i;
        }
    }
    cout<<Ans;
}