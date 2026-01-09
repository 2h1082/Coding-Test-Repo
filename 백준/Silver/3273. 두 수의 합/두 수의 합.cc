#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, X;
    cin>>N;
    
    vector<int> Num(N,0);
    for(auto& n : Num) cin>>n;
    sort(Num.begin(),Num.end());
    cin>>X;
    
    int Ans=0, L=0, R=N-1;
    while(L<R)
    {
        int Sum=Num[L]+Num[R];
        if(Sum==X)
        {
            ++Ans;
            ++L;
            --R;
        }
        else if(Sum < X)
        {
            ++L;
        }
        else
        {
            --R;
        }
    }
    
    cout<<Ans;
}