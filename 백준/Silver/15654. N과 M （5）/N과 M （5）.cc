#include "bits/stdc++.h"
using namespace std;

int N,M;
vector<int> A;
vector<bool> Used;
void DFS(vector<int>& Ans)
{
    if(Ans.size()==M)
    {
        for(int& a : Ans) cout<<a<<' ';
        cout<<'\n';
        return;
    }
    for(int i=0;i<N;++i)
    {
        if(Used[i]) continue;
        Used[i]=true;
        Ans.push_back(A[i]);
        DFS(Ans);
        Used[i]=false;
        Ans.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>M;
    A.assign(N,0);
    Used.assign(N,false);
    for(auto& a : A) cin>>a;
    sort(A.begin(),A.end());
    
    vector<int> Ans;
    DFS(Ans);
}