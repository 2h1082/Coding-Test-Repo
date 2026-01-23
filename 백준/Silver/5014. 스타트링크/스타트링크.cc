#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int F,S,G,U,D;
    cin>>F>>S>>G>>U>>D;
    
    vector<int> Dist(F+1,-1);
    queue<int> Q;
    Q.push(S);
    Dist[S]=0;
    while(!Q.empty())
    {
        int Cur=Q.front();
        Q.pop();
        for(int Nxt : {Cur-D, Cur+U})
        {
            if(Nxt<1 || Nxt>F || Nxt==Cur || Dist[Nxt]!=-1) continue;
            Q.push(Nxt);
            Dist[Nxt]=Dist[Cur]+1;
        }
    }
    if(Dist[G]==-1) cout<<"use the stairs";
    else            cout<<Dist[G];
}