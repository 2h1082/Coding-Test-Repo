#include "bits/stdc++.h"
using namespace std;

int N, Max=0;
vector<pair<int,int>> A;
void DFS(int Cur, int Cnt)
{
    if(Cur==N)
    {
        Max=max(Max,Cnt);
        return;
    }
    if(A[Cur].first <= 0)
    {
        DFS(Cur+1,Cnt);
        return;
    }
    bool bHit=false;
    for(int i=0;i<N;++i)
    {
        if(i==Cur || A[i].first <= 0) continue;
        int NxtCnt=Cnt;
        A[Cur].first-=A[i].second;
        A[i].first-=A[Cur].second;
        if(A[Cur].first<=0) ++NxtCnt;
        if(A[i].first<=0)   ++NxtCnt;
        DFS(Cur+1,NxtCnt);
        A[Cur].first+=A[i].second;
        A[i].first+=A[Cur].second;
        bHit=true;
    }
    if(!bHit)
    {
        DFS(Cur+1,Cnt);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N;
    A.resize(N);
    for(auto& [C,W]:A) cin>>C>>W;
    DFS(0,0);
    cout<<Max;
}