#include <bits/stdc++.h>

using namespace std;

int dr[]={-1,0,1,0}; //위, 우, 아래, 좌
int dc[]={0,1,0,-1};

int IsCycle(int sx, int sy, int dir, vector<string>& g, vector<vector<vector<bool>>>& v)
{
    int R=g.size(), C=g[0].size();
    int x=sx, y=sy, d=dir;
    int count=0;
    while(!v[d][y][x])
    {
        v[d][y][x]=true;
        count++;
        char nd=g[y][x];
        if(nd=='L') d=(d+3)%4;
        else if(nd=='R') d=(d+1)%4;
        y=(y+dr[d]+R)%R;
        x=(x+dc[d]+C)%C;
    }
    if((sx==x)&&(sy==y)&&(dir==d)) return count;
    else                    return 0;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int R=grid.size();
    int C=grid[0].size();
    vector<vector<vector<bool>>> visited(4,vector<vector<bool>>(R,vector<bool>(C,false)));
    for(int r=0;r<R;r++)
    {
        for(int c=0;c<C;c++)
        {
            for(int i=0;i<4;i++)
            {
                int Dir=IsCycle(c,r,i,grid,visited);
                if(Dir)
                {
                    answer.push_back(Dir);
                }
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}