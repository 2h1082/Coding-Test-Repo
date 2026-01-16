#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,M;
    cin>>N>>M;
    
    deque<int> Q(N);
    int Cnt=0;
    iota(Q.begin(),Q.end(),1);
    
    while(M--)
    {
        int Target=0;
        cin>>Target;
        
        int Idx=0;
        for(int i=0;i<Q.size();++i) 
        {
            if(Q[i]==Target) 
            {
                Idx=i;
                break;
            }
        }
        int L=Idx;
        int R=Q.size()-Idx;
        if(L<=R)
        {
            for(int i=0;i<L;++i)
            {
                Q.push_back(Q.front());
                Q.pop_front();
                ++Cnt;
            }
        }
        else
        {
            for(int i=0;i<R;++i)
            {
                Q.push_front(Q.back());
                Q.pop_back();
                ++Cnt;
            }
        }
        Q.pop_front();
    }
    cout<<Cnt;
}