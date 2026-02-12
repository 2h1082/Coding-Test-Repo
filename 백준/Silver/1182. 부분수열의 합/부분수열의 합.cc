#include "bits/stdc++.h"
using namespace std;

int N, S, Cnt=0;
vector<int> A;
void DFS(int Cur, int Sum)
{
    for(int i=Cur;i<N;++i)
    {
        int NxtSum=Sum+A[i];
        if(NxtSum==S) ++Cnt;
        DFS(i+1,NxtSum);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>S;
    A.resize(N);
    for(auto& a : A) cin>>a;
    DFS(0,0);
    cout<<Cnt;
}