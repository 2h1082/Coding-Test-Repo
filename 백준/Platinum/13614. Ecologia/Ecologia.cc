#include "bits/stdc++.h"
using namespace std;

struct Node
{
    int Y,X,Val,Idx;
};
int N, M, Ans=0;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
vector<vector<int>> Map;
vector<bool> Used;
vector<Node> SortedNode;
vector<int> GlobalPref;

void DFS(int Cnt, int CurSum, vector<int>& Cand)
{
    if(CurSum+GlobalPref[M-Cnt] <= Ans) return;
    
    if(Cnt==M)
    {
        Ans=max(Ans,CurSum);
        return;
    }
    
    for(int i=0;i<Cand.size();++i)
    {
        int Cur=Cand[i];
        int y=Cur/N, x=Cur%N;
        
        vector<int> NxtCand;
        for(int j=i+1;j<Cand.size();++j) NxtCand.push_back(Cand[j]);
        
        vector<int> AddedNode;
        for(int d=0;d<4;++d)
        {
            int ny=y+dy[d], nx=x+dx[d];
            if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
            
            int Idx=ny*N+nx;
            if(Used[Idx]) continue;
            
            Used[Idx]=true;
            NxtCand.push_back(Idx);
            AddedNode.push_back(Idx);
        }
        DFS(Cnt+1,CurSum+Map[y][x],NxtCand);
        
        for(int Idx : AddedNode) Used[Idx]=false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    
    Map.assign(N,vector<int>(N,0));
    int Total=N*N;
    SortedNode.resize(Total);
    vector<int> AllVals;
    GlobalPref.assign(M,0);
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            cin>>Map[i][j];
            AllVals.push_back(Map[i][j]);
            
            int Idx=i*N+j;
            SortedNode[Idx]={i,j,Map[i][j],Idx};
        }
    }
    sort(AllVals.rbegin(),AllVals.rend());
    for(int i=0;i<M-1;++i) GlobalPref[i+1]=GlobalPref[i]+AllVals[i];
    sort(SortedNode.begin(),SortedNode.end(),[](const Node& a, const Node& b){
        return a.Val > b.Val;
    });
    
    for(int i=0;i<Total;++i)
    {
        Node& Root=SortedNode[i];
        int StartIdx=Root.Idx;
        Used.assign(Total,false);
        for(int k=0;k<=StartIdx;++k) Used[k]=true;
        
        vector<int> InitialCand(4,-1);
        for(int d=0;d<4;++d)
        {
            int ny=Root.Y+dy[d], nx=Root.X+dx[d];
            if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
            int NxtIdx=ny*N+nx;
            if(NxtIdx > StartIdx)
            {
                Used[NxtIdx]=true;
                InitialCand.push_back(NxtIdx);
            }
        }
        DFS(1,Root.Val,InitialCand);
    }
    
    cout<<Ans;
    return 0;
}
