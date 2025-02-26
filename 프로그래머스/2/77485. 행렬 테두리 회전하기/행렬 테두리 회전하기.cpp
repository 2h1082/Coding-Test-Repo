#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    vector<vector<int>> Matrix(rows,vector<int>(columns));
    int k=1;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            Matrix[i][j]=k++;
        }
    }
    for(vector<int> quer : queries)
    {
        int y1=quer[0]-1, x1=quer[1]-1, y2=quer[2]-1, x2=quer[3]-1;
        int LenX=x2-x1;
        int LenY=y2-y1;
        int temp=Matrix[y1][x1];
        int Min=temp;
        int curX=x1, curY=y1;
        int dir=0;
        Matrix[y1][x1]=Matrix[y1+1][x1];
        for(int i=0;i<2*(LenX+LenY);i++)
        {
            int nextX=curX+dx[dir], nextY=curY+dy[dir];
            if(nextX>x2 || nextY>y2 || nextX<x1 || nextY<y1)
            {
                dir++;
                nextX=curX+dx[dir];
                nextY=curY+dy[dir];
            }
            Min=min(Min,Matrix[nextY][nextX]);
            swap(Matrix[nextY][nextX],temp);
            curX=nextX;
            curY=nextY;
        }
        answer.push_back(Min);
    }
    
    return answer;
}