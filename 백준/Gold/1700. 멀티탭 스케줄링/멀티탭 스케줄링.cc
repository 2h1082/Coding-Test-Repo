#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,K;
    cin>>N>>K;
    
    vector<queue<int>> Idx(K+1);
    vector<int> A(K);
    set<int> Plugged;
    for(int i=0;i<K;++i)
    {
        cin>>A[i];
        Idx[A[i]].push(i);
    }
    int Cnt=0;
    for(auto& a : A)
    {
        Idx[a].pop();
        if(Plugged.count(a)) continue;
        if(Plugged.size()<N)
        {
            Plugged.insert(a);
        }
        else
        {
            int Target=-1, LastIdx=-1;
            
            for(int p : Plugged)
            {
                if(Idx[p].empty())
                {
                    Target=p;
                    break;
                }
                if(Idx[p].front() > LastIdx)
                {
                    LastIdx=Idx[p].front();
                    Target=p;
                }
            }
            Plugged.erase(Target);
            Plugged.insert(a);
            ++Cnt;
        }
    }
    cout<<Cnt;
}