#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> Board;
int N=0, Max=0;
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};

void Rotate(vector<vector<int>>& Vec)
{
    vector<vector<int>> TempVec=Vec;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            Vec[i][j]=TempVec[j][N-1-i];
        }
    }
}
void MoveAndMerge(int Dir)
{
    for(int Rot=0;Rot<Dir;++Rot)
    {
        Rotate(Board);
    }
    for(int j=0;j<N;++j)
    {
        vector<int> Col;
        for(int i=0;i<N;++i)
        {
            if(Board[i][j]!=0)
            {
                Col.push_back(Board[i][j]);
            }
        }
        vector<int> Merged;
        for(int i=0;i<Col.size();++i)
        {
            if(i+1<Col.size()&&Col[i]==Col[i+1])
            {
                Merged.push_back(Col[i]*2);
                i++;
            }
            else
            {
                Merged.push_back(Col[i]);
            }
        }
        for(int i=0;i<N;++i)
        {
            Board[i][j]=0;
        }
        for(int i=0;i<Merged.size();++i)
        {
            Board[i][j]=Merged[i];
        }
    }
}
void DFS(int Count)
{
    if(Count==5)
    {
        for(auto& Row : Board)
        {
            for(auto& Cell : Row)
            {
                Max=max(Max,Cell);
            }
        }
        return;
    }
    vector<vector<int>> Temp=Board;
    
    for(int i=0;i<4;++i)
    {
        MoveAndMerge(i);
        DFS(Count+1);
        Board=Temp;
    }
}

int main()
{
    cin>>N;
    
    Board.assign(N,vector<int>(N,0));
    for(auto& Row:Board)
    {
        for(auto& Cell:Row)
        {
            cin>>Cell;
        }
    }
    DFS(0);
    cout<<Max;
}