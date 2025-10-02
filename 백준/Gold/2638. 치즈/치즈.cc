#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> Paper;
vector<pair<int,int>> Cheese;
vector<vector<bool>> ExternalAir;
int CheeseCount=0;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int N=0,M=0;
void CheckExternalAir()
{
    queue<pair<int,int>> q;
    q.push({0,0});
    ExternalAir[0][0]=true;
    while(!q.empty())
    {
        auto& [x,y]=q.front();
        q.pop();
        for(int i=0;i<4;++i)
        {
            int NextY=dy[i]+y;
            int NextX=dx[i]+x;
            if(NextY>=0&&NextY<N&&NextX>=0&&NextX<M&&!Paper[NextY][NextX]&&!ExternalAir[NextY][NextX])
            {
                ExternalAir[NextY][NextX]=true;
                q.push({NextX,NextY});
            }
        }
    }
}
void MeltDown(vector<vector<int>> Origin)
{
    vector<pair<int,int>> RemainCheese;
    for(auto& C : Cheese)
    {
        auto& [y, x]=C;
        int Exposed=0;
        for(int i=0;i<4;++i)
        {
            int NextY=y+dy[i];
            int NextX=x+dx[i];
            if(NextY>=0&&NextY<N&&NextX>=0&&NextX<M&&ExternalAir[NextY][NextX])
            {
                Exposed++;
                if(Exposed>1) break;
            }
        }
        if(Exposed>1)
        {
            CheeseCount--;
            Paper[y][x]=0;
        }
        else
        {
            RemainCheese.push_back({y,x});
        }
    }
    Cheese=move(RemainCheese);
}
int main()
{
    cin>>N>>M;
    Paper.assign(N,vector<int>(M,0));
    
    for(int r=0;r<N;++r)
    {
        for(int c=0;c<M;++c)
        {
            cin>>Paper[r][c];
            if(Paper[r][c]==1)
            {
                Cheese.push_back({r,c}); // y, x
                CheeseCount++;
            }
        }
    }
    int Time=0;
    while(CheeseCount)
    {
        ExternalAir.assign(N,vector<bool>(M,false));
        CheckExternalAir();
        MeltDown(Paper);
        Time++;
    }
    cout<<Time;
}