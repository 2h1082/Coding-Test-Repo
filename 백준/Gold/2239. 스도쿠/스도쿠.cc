#include <bits/stdc++.h>

using namespace std;
vector<string> Board;
vector<pair<int,int>> CheckList;
vector<vector<bool>> Col;
vector<vector<bool>> Row;
vector<vector<bool>> Box;
int N=9;
void DFS(int Idx)
{
    if(Idx==CheckList.size())
    {
        for(auto& R : Board)
        {
            cout<<R<<"\n";
        }
        exit(0);
    }
    
    //const auto& [x,y]=CheckList[Idx];
    int x=CheckList[Idx].first;
    int y=CheckList[Idx].second;
    int BoxIdx=y/3*3+x/3;
    for(int k=1;k<=N;++k)
    {
        if(!Col[x][k]&&!Row[y][k]&&!Box[BoxIdx][k])
        {
            Col[x][k]=true;
            Row[y][k]=true;
            Box[BoxIdx][k]=true;
            Board[y][x]=k+'0';
            DFS(Idx+1);
            Col[x][k]=false;
            Row[y][k]=false;
            Box[BoxIdx][k]=false;
            Board[y][x]='0';
        }
    }
}
int main()
{
    
    Board.assign(N,string());
    Col.assign(N,vector<bool>(N+1,false));
    Row.assign(N,vector<bool>(N+1,false));
    Box.assign(N,vector<bool>(N+1,false));
    for(int i=0;i<N;++i)
    {
        cin>>Board[i];
        for(int j=0;j<N;++j)
        {
            if(Board[i][j]=='0') 
            {
                CheckList.push_back({j,i}); //X, Y
            }
            else
            {
                int Num=Board[i][j]-'0';
                Col[j][Num]=true;
                Row[i][Num]=true;
                Box[i/3*3+j/3][Num]=true;
            }
        }
    }
    DFS(0);
}