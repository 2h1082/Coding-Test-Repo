#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    vector<int> Num(N,0);    
    for(auto& n : Num) cin>>n;
    sort(Num.begin(),Num.end());
    
    int Cnt=0;
    for(int i=0;i<N;++i)
    {
        int L=0, R=N-1;
        while(L<R)
        {
            if(i==L)
            {
                L++;
                continue;
            }
            if(i==R)
            {
                R--;
                continue;
            }
            int Sum=Num[L]+Num[R];
            if(Sum==Num[i]) 
            {
                Cnt++;
                break;
            }
            else if(Sum < Num[i]) L++;
            else                  R--;
        }
    }
    cout<<Cnt;
}