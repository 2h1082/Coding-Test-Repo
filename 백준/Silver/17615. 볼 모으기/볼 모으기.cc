#include "bits/stdc++.h"
using namespace std;

int N;
string S;
int Count(char C, bool Left)
{
    int Cnt=0;
    if(Left)
    {
        int i=0;
        while(i<N && S[i]==C) ++i;
        for(;i<N;++i)
        {
            if(S[i]==C) ++Cnt;
        }
    }
    else
    {
        int i=N-1;
        while(i>=0 && S[i]==C) --i;
        for(;i>=0;--i)
        {
            if(S[i]==C) ++Cnt;
        }
    }
    return Cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>S;
    
    int Ans=min({Count('R',true),Count('R',false),Count('B',true),Count('B',false)});
    cout<<Ans;
}