#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll solution(int N, vector<int> Times) 
{
    sort(Times.begin(),Times.end());
    ll L=1, R=(ll)N*Times.back();
    while(L<R)
    {
        ll M=(L+R)/2;
        ll Sum=0;
        for(int& T : Times)
        {
            Sum+=M/T;
            if(Sum>=N) break;
        }
        if(Sum>=N) R=M;
        else       L=M+1;
    }
    
    return L;
}