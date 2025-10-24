#include <bits/stdc++.h>

using namespace std;
struct State
{
    int R=0;
    int C=0;
    int S=0;
    int D=0;
    int Z=0;
};
int dr[4]={-1,1,0,0};
int dc[4]={0,0,1,-1};
vector<State> Sharks;
vector<bool> Visited;
vector<vector<int>> Map;
int R,C,M;

void MoveShark()
{
    vector<vector<int>> NextMap(R,vector<int>(C,-1));
    for(int i=0;i<M;++i)
    {
        if(Visited[i]) continue;
        State& Cur=Sharks[i];
        
        if(Cur.D<2)
        {
            int Cycle=2*(R-1);
            int Dist=Cur.S%Cycle;
            int Raw=Cur.R+dr[Cur.D]*Dist;
            Raw=((Raw%Cycle)+Cycle)%Cycle;
            Cur.R=(Raw<R) ? Raw : (Cycle-Raw);
            if(Raw>=R||Raw<0) Cur.D^=1;
        }
        else
        {
            int Cycle=2*(C-1);
            int Dist=Cur.S%Cycle;
            int Col=Cur.C+dc[Cur.D]*Dist;
            Col=((Col%Cycle)+Cycle)%Cycle;
            Cur.C=(Col<C) ? Col : (Cycle-Col);
            if(Col>=C||Col<0) Cur.D^=1;
        }
        if(NextMap[Cur.R][Cur.C]==-1)
        {
            NextMap[Cur.R][Cur.C]=i;
        }
        else
        {
            if(Sharks[NextMap[Cur.R][Cur.C]].Z<Cur.Z)
            {
                Visited[NextMap[Cur.R][Cur.C]]=true;
                NextMap[Cur.R][Cur.C]=i;
            }
            else
            {
                Visited[i]=true;
            }
        }
    }
    Map=move(NextMap);
}
int main()
{
    
    cin>>R>>C>>M;
    Map.assign(R,vector<int>(C,-1));
    Sharks.resize(M);
    Visited.assign(M,false);
    for(int i=0;i<M;++i)
    {
        cin>>Sharks[i].R>>Sharks[i].C>>Sharks[i].S>>Sharks[i].D>>Sharks[i].Z;
        Sharks[i].R--;
        Sharks[i].C--;
        Sharks[i].D--;
        Map[Sharks[i].R][Sharks[i].C]=i;
    }
    
    int Cnt=0;
    for(int c=0;c<C;++c)
    {
        for(int r=0;r<R;++r)
        {
            if(Map[r][c]==-1) continue;
            Visited[Map[r][c]]=true;
            Cnt+=Sharks[Map[r][c]].Z;
            Map[r][c]=-1;
            break;
        }
        MoveShark();
    }
    cout<<Cnt;
}