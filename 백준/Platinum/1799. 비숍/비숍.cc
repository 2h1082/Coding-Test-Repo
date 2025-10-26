#include <bits/stdc++.h>

using namespace std;
vector<bool> Diag1,Diag2;
vector<pair<int,int>> Black,White;
int N=0, Max=0;
bool Possible(int y, int x)
{
    return !(Diag1[y-x+N-1]||Diag2[y+x]);
}

void DFS(vector<pair<int,int>>& Cells,int Idx, int Cnt, int& Max)
{
    if(Idx==Cells.size())
    {
        Max=max(Max,Cnt);
        return;
    }
    auto [y,x]=Cells[Idx];
    if(Possible(y,x))
    {
        Diag1[y-x+N-1]=true;
        Diag2[y+x]=true;
        DFS(Cells,Idx+1,Cnt+1,Max);
        Diag1[y-x+N-1]=false;
        Diag2[y+x]=false;
    }
    DFS(Cells,Idx+1,Cnt,Max);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin>>N;
    
    Diag1.assign(2*N,false);
    Diag2.assign(2*N,false);
    for(int r=0;r<N;++r)
    {
        for(int c=0;c<N;++c)
        {
            int Num=0;
            cin>>Num;
            if(Num!=1) continue;
            if((r+c)%2) White.push_back({r,c});
            else        Black.push_back({r,c});
            
        }
    }
    int MaxB=0,MaxW=0;
    DFS(Black,0,0,MaxB);
    DFS(White,0,0,MaxW);
    cout<<MaxB+MaxW;
}
