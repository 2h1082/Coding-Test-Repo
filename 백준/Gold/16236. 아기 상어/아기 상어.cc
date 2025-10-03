#include <bits/stdc++.h>

using namespace std;

int N=0;
vector<vector<int>> Map;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int Level=2;
int EXP=0;
int Time=0;
void CheckFish(pair<int,int>& Start)
{
    int Min=INT_MAX;
    queue<tuple<int,int,int>> q;
    vector<vector<bool>> Visited(N,vector<bool>(N,false));
    priority_queue<pair<int,int>> Candidate;
    Visited[Start.first][Start.second]=true;
    q.push(make_tuple(Start.first,Start.second,0));
    while(!q.empty())
    {
        //auto& [Y,X,Count]=q.front();
        int Y=get<0>(q.front());
        int X=get<1>(q.front());
        int Count=get<2>(q.front());
        q.pop();
        if(Count>Min) continue;
        for(int i=0;i<4;++i)
        {
            int NextX=X+dx[i];
            int NextY=Y+dy[i];
            if(NextX>=0&&NextX<N&&NextY>=0&&NextY<N&&!Visited[NextY][NextX]&&Map[NextY][NextX]<=Level)
            {
                Visited[NextY][NextX]=true;
                if(Level>Map[NextY][NextX]&&Map[NextY][NextX]>0&&Min>=Count+1)
                {
                    Candidate.push({-NextY,-NextX});
                    Min=Count+1;
                }
                q.push({NextY,NextX,Count+1});
            }
        }
    }
    if(Candidate.empty())
    {
        Start={-1,-1};
    }
    else
    {
        Start.first=-Candidate.top().first;
        Start.second=-Candidate.top().second;
        Time+=Min;
        EXP++;
        if (EXP==Level)
        {
            Level++;
            EXP=0;
        }
        Map[Start.first][Start.second]=0;
    }
}
int main()
{
    cin>>N;
    Map.assign(N,vector<int>(N,0));
    pair<int,int> Start;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            cin>>Map[i][j];
            if(Map[i][j]==9)
            {
                Start={i,j}; //Y, X
                Map[i][j]=0;
            }
        }
    }
    while(Start.first!=-1)
    {
        CheckFish(Start);
    }
    cout<<Time;
}