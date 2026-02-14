#include "bits/stdc++.h"
using namespace std;

int N,M;
vector<int> A;
vector<bool> Used;
void DFS(vector<int>& Ans)
{
    if(Ans.size()==M)
    {
        for(auto& a : Ans) cout<<a<<' ';
        cout<<'\n';
        return;
    }
    int Prev=-1;
    for(int i=0;i<N;++i)
    {
        if(Used[i] || Prev==A[i]) continue;
        Used[i]=true;
        Ans.push_back(A[i]);
        DFS(Ans);
        Ans.pop_back();
        Used[i]=false;
        Prev=A[i];
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