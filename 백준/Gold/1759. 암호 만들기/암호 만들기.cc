#include "bits/stdc++.h"
using namespace std;

int L,C1;
vector<char> A;
bool IsVowel(char C)
{
    return (C=='a' || C=='e' || C=='i' || C=='o' || C=='u');
}
void DFS(string& Ans, int Cur, int V, int C)
{
    if(Ans.length()==L)
    {
        if(V>=1 && C>=2) cout<<Ans<<'\n';
        return;
    }
    for(int i=Cur;i<C1;++i)
    {
        Ans+=A[i];
        if(IsVowel(A[i]))  DFS(Ans,i+1,V+1,C);
        else               DFS(Ans,i+1,V,C+1);
        Ans.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>L>>C1;
    A.assign(C1,' ');
    for(auto& a : A) cin>>a;
    sort(A.begin(),A.end());
    
    string Ans="";
    DFS(Ans,0,0,0);
}