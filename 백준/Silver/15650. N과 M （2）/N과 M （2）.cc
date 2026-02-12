#include "bits/stdc++.h"
using namespace std;

int N,M;
void DFS(int Cur, vector<int>& A)
{
    if(A.size()==M)
    {
        for(int a : A) cout<<a<<' ';
        cout<<'\n';
        return;
    }
    for(int i=Cur+1;i<=N;++i)
    {
        A.push_back(i);
        DFS(i,A);
        A.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>M;
    vector<int> Ans;
    DFS(0,Ans);
}