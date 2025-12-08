#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,K;
    cin>>N>>K;
    
    deque<int> R(2*N,0), D(2*N,0);
    for(auto& d : D) cin>>d;
    
    int ZeroCnt=0, Ans=0;
    while(ZeroCnt < K)
    {
        Ans++;
        
        D.push_front(D.back());
        D.pop_back();
        
        R.push_front(R.back());
        R.pop_back();
        
        R[N-1]=0;
        
        for(int i=N-2;i>=0;--i)
        {
            if(R[i] && !R[i+1] && D[i+1]>0)
            {
                R[i]=0;
                R[i+1]=1;
                D[i+1]--;
                if(D[i+1]==0) ZeroCnt++;
            }
        }
        R[N-1]=0;
        
        if(D[0]>0)
        {
            R[0]=1;
            D[0]--;
            if(D[0]==0) ZeroCnt++;
        }
    }
    cout<<Ans;
}