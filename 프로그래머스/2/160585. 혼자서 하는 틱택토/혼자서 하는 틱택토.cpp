#include <bits/stdc++.h>

using namespace std;

bool bIsOverFirst=false, bIsOverSecond=false;
int dy[]={1,0,1,-1,0,-1,-1,1};
int dx[]={0,1,1,0,-1,-1,1,-1};
void DFS(vector<string>& board, int row, int col, int cnt, char c, int idx)
{
    if(row>2||row<0||col>2||col<0) return;   
    if(board[row][col]!=c) return;
    
    if(cnt==3)
    {
        if(c=='O') bIsOverFirst=true;
        else       bIsOverSecond=true;
        return;
    }
    DFS(board,row+dy[idx],col+dx[idx],cnt+1,c,idx);
    
    return;
}

int solution(vector<string> board) {
    int OCnt=0, XCnt=0;
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]=='O')
            {
                for(int k=0;k<8;k++) DFS(board,i,j,1,'O',k);
                OCnt++;
            }
            else if(board[i][j]=='X')
            {
                for(int k=0;k<8;k++) DFS(board,i,j,1,'X',k);
                XCnt++; 
            }  
        }
    }
    if(OCnt==0&&XCnt==0) return 1;
    int dif=OCnt-XCnt;
    //cout<<dif<< bIsOverFirst<<bIsOverSecond;
    if(dif>1||dif<0) return 0;
    if((bIsOverFirst&&dif!=1)||(bIsOverSecond&&dif!=0)||(bIsOverFirst==true&&bIsOverSecond==true)) return 0;
    
    return 1;
}