#include "bits/stdc++.h"
using namespace std;

string S,T;
bool DFS(string Cur)
{
    if(Cur==S) return true;
    if(Cur.length()==S.length()) return false;
    
    if(!Cur.empty() && Cur.back()=='A')
    {
        string Nxt=Cur.substr(0,Cur.size()-1);
        if(DFS(Nxt)) return true;
    }
    if(!Cur.empty() && Cur.front()=='B')
    {
        string Nxt=Cur.substr(1);
        reverse(Nxt.begin(),Nxt.end());
        if(DFS(Nxt)) return true;
    }

    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>S>>T;
    
    if(DFS(T)) cout<<1;
    else       cout<<0;
}