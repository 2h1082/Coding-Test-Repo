#include "bits/stdc++.h"
using namespace std;

int N=0, M=0;
bool IsPossible(vector<int>& Num, int Max)
{
    int Sum=0;
    for (auto n : Num)
    {
        Sum+=min(Max,n);
        if(Sum>M) return false;
    }
    return Sum<=M;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N;
    vector<int> Num(N,0);
    int MaxVal=0;
    for(auto& n : Num)
    {
        cin>>n;
        MaxVal=max(MaxVal,n);
    }
    cin>>M;
    
    int L=0, R=MaxVal;
    while (L<R)
    {
        int Mid=(L+R)/2 + 1;   
        if (IsPossible(Num,Mid))         L=Mid;
        else                             R=Mid-1;
    }
    cout<<L;
}