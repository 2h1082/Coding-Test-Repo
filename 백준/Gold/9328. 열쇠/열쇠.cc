#include <bits/stdc++.h>

using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int H=0, W=0;

int main()
{
    int T=0;
    cin>>T;
    while(T--)
    {
        cin>>H>>W;
        vector<string> Map(H);
        queue<pair<int,int>> q;
        int DocCount=0;
        vector<vector<bool>> Visited(H,vector<bool>(W,false));
        for(int r=0;r<H;++r)
        {
            cin>>Map[r];
        }
        for(int r=0;r<H;++r)
        {
            for(int c=0;c<W;++c)
            {
                if((r==0||r==H-1||c==0||c==W-1)&&Map[r][c]!='*')
                {
                    q.push({r,c});
                    Visited[r][c]=true;
                }
            }
        }
        vector<bool> HaveKey(26,false);
        string Keys;
        cin>>Keys;
        if(Keys!="0")
        {
            for(auto& K : Keys)
            {
                HaveKey[K-'a']=true;
            }
        }
        queue<pair<int,int>> DoorQ;
        while(1)
        {
            bool bHaveNewKey=false;
            while(!DoorQ.empty())
            {
                q.push(DoorQ.front());
                DoorQ.pop();
            }
            while(!q.empty())
            {
                auto [y, x] = q.front();
                q.pop();
                char Cell=Map[y][x];
                if(Cell=='$')
                {
                    DocCount++;
                }
                else if(Cell>='A'&&Cell<='Z')
                {
                    if(!HaveKey[Cell-'A'])
                    {
                        DoorQ.push({y,x});
                        continue;
                    }
                }
                else if(Cell>='a'&&Cell<='z')
                {
                    if(!HaveKey[Cell-'a'])
                    {
                        HaveKey[Cell-'a']=true;
                        bHaveNewKey=true;
                    }
                }
                for(int i=0;i<4;++i)
                {
                    int NextY=y+dy[i];
                    int NextX=x+dx[i];
                    if(NextY>=0&&NextY<H&&NextX>=0&&NextX<W&&!Visited[NextY][NextX]&&Map[NextY][NextX]!='*')
                    {
                        q.push({NextY,NextX});
                        Visited[NextY][NextX]=true;
                    }
                }
            }
            
            if(!bHaveNewKey) break;
        }
        cout<<DocCount<<"\n";
    }
}