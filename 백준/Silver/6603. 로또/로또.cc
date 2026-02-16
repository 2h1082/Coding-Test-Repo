#include "bits/stdc++.h"
using namespace std;

int K;
vector<int> A;
void DFS(vector<int>& Ans, int Cur)
{
    int Cnt=Ans.size();
    if(Cnt==6)
    {
        for(auto& a : Ans) cout<<a<<' ';
        cout<<'\n';
        return;
    }
    for(int i=Cur;i<K;++i)
    {
        Ans.push_back(A[i]);
        DFS(Ans,i+1);
        Ans.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(1)
    {
        cin>>K;
        if(!K) break;
        
        A.clear();
        A.assign(K,0);
        for(auto& a : A) cin>>a;
        vector<int> Ans;
        DFS(Ans,0);
        cout<<'\n';
    }
}