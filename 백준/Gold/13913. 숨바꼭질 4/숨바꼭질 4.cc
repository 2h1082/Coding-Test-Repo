#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,K;
    cin>>N>>K;
    
    vector<int> Prev(200001,-1);
    queue<int> Q;
    Prev[N]=N;
    Q.push(N);
    bool bIsFound=false;
    // BFS
    while(!Q.empty() && !bIsFound)
    {
        int Cur=Q.front();
        Q.pop();
        for(int Nxt : {Cur-1, Cur+1, Cur*2})
        {
            if(Nxt<0 || Nxt>200000 || Prev[Nxt]!=-1) continue;
            Prev[Nxt]=Cur;
            if(Nxt==K)
            {
                bIsFound=true;
                break;
            }
            Q.push(Nxt);
        }
    }
    
    vector<int> Ans(1,K);
    for(int Nxt=Prev[K];Nxt!=N;Nxt=Prev[Nxt]) Ans.push_back(Nxt);
    if(N!=K) Ans.push_back(N);
    
    cout<<Ans.size()-1<<'\n';
    for(auto It=Ans.rbegin();It!=Ans.rend();++It) cout<<*It<<' ';
}