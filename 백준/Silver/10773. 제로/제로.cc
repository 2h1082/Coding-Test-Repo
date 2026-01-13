#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int K;
    cin>>K;
    
    vector<int> A;
    while(K--)
    {
        int Num;
        cin>>Num;
        
        if(Num) A.push_back(Num);
        else    A.pop_back();
    }
    cout<<accumulate(A.begin(),A.end(),0);
}