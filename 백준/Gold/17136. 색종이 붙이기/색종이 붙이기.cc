#include "bits/stdc++.h"
using namespace std;
vector<vector<int>> B;
int P[6]={0,5,5,5,5,5};
int Min=INT_MAX;

bool CanAttach(int y, int x, int Size)
{
    if(y+Size>10 || x+Size>10) return false;
    for(int i=y;i<y+Size;++i)
    {
        for(int j=x;j<x+Size;++j)
        {
            if(!B[i][j]) return false;
        }
    }
    return true;
}
void Attach(int y, int x, int Size, int Val)
{
    for(int i=y;i<y+Size;++i)
    {
        for(int j=x;j<x+Size;++j)
        {
            B[i][j]=Val;
        }
    }
}
void DFS(int Cnt)
{
    if(Cnt>=Min) return;
    
    int cy=-1, cx=-1;
    for(int i=0;i<10;++i)
    {
        for(int j=0;j<10;++j)
        {
            if(!B[i][j]) continue;
            
            cy=i;
            cx=j;
            break;
        }
        if(cy!=-1) break;
    }

    if(cy==-1)
    {
        Min=min(Min,Cnt);
        return;
    }
    
    for(int Size=5;Size>=1;--Size)
    {
        if(!P[Size]) continue;
        if(!CanAttach(cy,cx,Size)) continue;
        
        Attach(cy,cx,Size,0);
        --P[Size];
        DFS(Cnt+1);
        Attach(cy,cx,Size,1);
        ++P[Size];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    B.assign(10,vector<int>(10,0));
    for(auto& r : B)
    {
        for(auto& c : r)
        {
            cin>>c;
        }
    }
    DFS(0);
    cout<<(Min==INT_MAX ? -1 : Min);
}