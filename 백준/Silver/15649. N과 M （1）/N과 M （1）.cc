#include <bits/stdc++.h>
using namespace std;
int N,M;
vector<int> Num, Out;
vector<bool> Visited;
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
        if(Visited[i]) continue;
        Visited[i]=true;
        Out.push_back(Num[i]);
        DFS(Cnt+1);
        Out.pop_back();
        Visited[i]=false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>M;
    Num.assign(N,0);
    Visited.assign(N,false);
    iota(Num.begin(),Num.end(),1);
    DFS(0);
}