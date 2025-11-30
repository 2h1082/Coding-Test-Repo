#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string S;
    cin>>S;
    
    int i=0;
    
    for(int j=1; ; ++j)
    {
        string Cur=to_string(j);
        for(char c : Cur)
        {
            if(c==S[i])
            {
                ++i;
                if(i==S.size())
                {
                    cout<<j;
                    return 0;
                }
            }
        }
    }
}