#include <bits/stdc++.h>

using namespace std;

bool CheckCross(vector<vector<bool>>& Map,int x, int y, int n)
{
    for(int i=0;i<n;i++)
    {
        if(x+i>=0&&x+i<n&&y+i>=0&&y+i<n)
        {
            if(Map[y+i][x+i]==true)
            {
                return false;
            }
        }
        if(x+i>=0&&x+i<n&&y-i>=0&&y-i<n)
        {
            if(Map[y-i][x+i]==true)
            {
                return false;
            }
        }
        if(x-i>=0&&x-i<n&&y+i>=0&&y+i<n)
        {
            if(Map[y+i][x-i]==true)
            {
                return false;
            }
        }
        if(x-i>=0&&x-i<n&&y-i>=0&&y-i<n)
        {
            if(Map[y-i][x-i]==true)
            {
                return false;
            }
        }
    }
    return true;
}
void DFS(int Row, int& answer, vector<bool>& bQueenExist, vector<vector<bool>>& Map, int n)
{
    bool Queen=false;
    if(Row==n)
    {
        answer++;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!bQueenExist[i])
        {
            if(CheckCross(Map,i,Row,n))
            {
                bQueenExist[i]=true;
                Map[Row][i]=true;
                DFS(Row+1,answer,bQueenExist,Map,n);
                bQueenExist[i]=false;
                Map[Row][i]=false;   
            }                
        }
    }
}
int solution(int n) {
    int answer = 0;
    vector<vector<bool>> ChessBoard(n,vector<bool>(n,false));
    vector<bool> bQueenExist(n,0);
    
    DFS(0,answer,bQueenExist,ChessBoard,n);
    return answer;
}