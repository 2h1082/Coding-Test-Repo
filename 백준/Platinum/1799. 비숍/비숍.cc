#include "bits/stdc++.h"
using namespace std;

int N;
vector<vector<int>> A;
vector<bool> Diag1, Diag2;
void DFS(int Cur, int Cnt, int& M, int& Max, vector<pair<int,int>>& Cand)
{
    if(Cur==M)
    {
        Max=max(Max,Cnt);
        return;
    }
    auto [Y,X]=Cand[Cur];
    DFS(Cur+1,Cnt,M,Max,Cand);
    if(!Diag1[Y-X+N] && !Diag2[Y+X]) 
    {
        Diag1[Y-X+N]=Diag2[Y+X]=true;
        DFS(Cur+1,Cnt+1,M,Max,Cand);
        Diag1[Y-X+N]=Diag2[Y+X]=false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N;
    A.assign(N,vector<int>(N,0));
    Diag1.assign(2*N,false);
    Diag2.assign(2*N,false);
    // 흰색, 흑색 칸은 비숍 배치에 서로 영향을 주지 않으니 아예 나누어 시뮬레이션 -> 시간 절약 가능
    // - 불필요한 경우의 수를 계산할 필요가 없어짐
    vector<pair<int,int>> B,W;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            cin>>A[i][j];
            if(!A[i][j]) continue;
            if((i+j)%2)  B.push_back({i,j});
            else         W.push_back({i,j});
                
        }
    }
    int MaxB=0, MaxW=0, SizeB=B.size(), SizeW=W.size();
    DFS(0,0,SizeB,MaxB,B);
    DFS(0,0,SizeW,MaxW,W);
    
    cout<<MaxW+MaxB;
}