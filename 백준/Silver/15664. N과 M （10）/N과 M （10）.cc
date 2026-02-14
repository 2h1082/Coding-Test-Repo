#include "bits/stdc++.h"
using namespace std;

int N,M;
vector<int> A;
void DFS(vector<int>& Ans, int Cur)
{
    if(Ans.size()==M)
    {
        for(auto& a : Ans) cout<<a<<' ';
        cout<<'\n';
        return;
    }
    
    int Prev=-1;
    for(int i=Cur;i<N;++i)
    {
        if(Prev==A[i]) continue;
        Ans.push_back(A[i]);
        DFS(Ans,i+1);
        Ans.pop_back();
        Prev=A[i];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>M;
    A.assign(N,0);
    for(auto& a : A) cin>>a;
    sort(A.begin(),A.end());
    
    vector<int> Ans;
    DFS(Ans,0);
}