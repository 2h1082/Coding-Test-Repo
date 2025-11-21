#include "bits/stdc++.h"
using namespace std;
#define y first
#define x second

vector<vector<int>> B;
vector<vector<bool>> Row,Col,Box;
bool DFS(int Cur, vector<pair<int,int>>& Z)
{
    if(Cur==Z.size())
    {
        for(auto& r : B)
        {
            for(auto& c : r)
            {
                cout<<c<<' ';
            }
            cout<<'\n';
        }
        return true;
    }
    int Y=Z[Cur].y, X=Z[Cur].x;
    int BoxIdx=X/3 + (Y/3)*3;
    for(int Num=0;Num<9;++Num)
    {
        if(!Row[Y][Num] && !Col[X][Num] && !Box[BoxIdx][Num])
        {
            Row[Y][Num]=Col[X][Num]=Box[BoxIdx][Num]=true;
            B[Y][X]=Num+1;
            if(DFS(Cur+1,Z)) return true;
            Row[Y][Num]=Col[X][Num]=Box[BoxIdx][Num]=false;
            B[Y][X]=0;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    B.assign(9,vector<int>(9,0));
    Row.assign(9,vector<bool>(9,false));
    Col.assign(9,vector<bool>(9,false));
    Box.assign(9,vector<bool>(9,false));
    vector<pair<int,int>> Zero;
    for(int i=0;i<9;++i)
    {
        for(int j=0;j<9;++j)
        {
            cin>>B[i][j];
            if(B[i][j]==0) Zero.push_back({i,j});
            else
            {
                int Num=B[i][j]-1, Idx=j/3 + (i/3)*3; 
                Row[i][Num]=true;
                Col[j][Num]=true;
                Box[Idx][Num]=true;
            }
        }
    }
    DFS(0,Zero);
}