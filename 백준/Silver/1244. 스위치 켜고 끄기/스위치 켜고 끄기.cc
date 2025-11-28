#include "bits/stdc++.h"
using namespace std;

void Switch(int& Num)
{
    if(!Num) Num=1;
    else     Num=0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    
    vector<int> S(N+1);
    for(int i=1;i<=N;++i) cin>>S[i];
    
    int M;
    cin>>M;
    
    while(M--)
    {
        int Gender, Num;
        cin>>Gender>>Num;
        
        if(Gender==1) // 배수 반전
        {
            for(int i=Num;i<=N;++i)
            {
                if(i%Num==0) Switch(S[i]);
            }
        }
        else // 대칭 구간 반전
        {
            int L=0;
            for(;(Num+L<=N) && (Num-L>0);++L)
            {
                if(S[Num+L] != S[Num-L]) break;
            }
            --L;
            for(int i=Num-L;i<=Num+L;++i) Switch(S[i]);
        }
    }
    for(int i=1;i<=N;++i)
    {
        cout<<S[i]<<' ';
        if(i%20==0) cout<<'\n';
    }
}