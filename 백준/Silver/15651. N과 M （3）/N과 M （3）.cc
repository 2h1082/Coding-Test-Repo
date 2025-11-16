#include "bits/stdc++.h"
using namespace std;

int N=0, M=0;
vector<int> Num, Out;

void DFS(int Cnt)
{
    if(Cnt==M) 
    {
        for(auto& o : Out) cout<<o<<' ';
        cout<<'\n';
        return;
    }
    for(int i=0;i<N;++i)
    {
        Out.push_back(Num[i]);
        DFS(Cnt+1);
        Out.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>M;
    Num.assign(N,0);
    iota(Num.begin(),Num.end(),1);
    DFS(0);
}