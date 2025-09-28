#include <iostream>
#include <vector>

using namespace std;
int N=0, Solution=0;
vector<vector<bool>> Board;
int dx[3]={0,-1,1};
int dy[3]={-1,-1,-1};
bool IsPossible(int X, int Y)
{
    for(int j=0;j<Y;++j)
    {
        if(Board[j][X]) return false;
        int Diff=Y-j;
        if(X-Diff>=0&&Board[j][X-Diff])
        {
            return false;
        }
        if(X+Diff<N&&Board[j][X+Diff])
        {
            return false;
        }
    }
    return true;
}
void NQueen(int Y, int Count)
{
    if(Count==N)
    {
        Solution++;
        return;
    }
    if(Y>=N) return;
    for (int i=0;i<N;++i)
    {
        if (IsPossible(i,Y))
        {
            Board[Y][i]=true;
            NQueen(Y+1,Count+1);
            Board[Y][i]=false;
        }
    }
}
int main()
{
    cin>>N;
    Board.assign(N,vector<bool>(N,false));
    
    
    NQueen(0,0);
    cout<<Solution;
}