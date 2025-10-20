
#include <ios>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
vector<string> Map;
vector<vector<bool>> Visited;
vector<int> GroupSize;
vector<vector<int>> GIDs;
int N,M;
int DFS(int y, int x, int GID)
{
    int Cnt=1;
    GIDs[y][x]=GID;
    for(int i=0;i<4;++i)
    {
        int Nx=dx[i]+x;
        int Ny=dy[i]+y;
        if(Nx>=0&&Nx<M&&Ny>=0&&Ny<N&&!Visited[Ny][Nx]&&Map[Ny][Nx]=='0')
        {
            Visited[Ny][Nx]=true;
            Cnt+=DFS(Ny,Nx,GID);
        }
    }
    return Cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    

    cin>>N>>M;
    
    Map.resize(N);
    
    for(auto& Row: Map)
    {
        cin>>Row;
    }
    vector<vector<int>> Res(N,vector<int>(M,0));
    GIDs.assign(N,vector<int>(M,0));
    Visited.assign(N,vector<bool>(M,false));
    int GroupID=1;
    GroupSize.push_back(0);
    for(int r=0;r<N;++r)
    {
        for(int c=0;c<M;++c)
        {
            if(Map[r][c]=='0'&&!Visited[r][c])
            {
                GroupSize.push_back(0);
                Visited[r][c]=true;
                GroupSize[GroupID]=DFS(r,c,GroupID);
                GroupID++;
            }
        }
    }
    for(int r=0;r<N;++r)
    {
        for(int c=0;c<M;++c)
        {
            if(Map[r][c]=='1')
            {
                set<int> s;
                Res[r][c]++;
                for(int i=0;i<4;++i)
                {
                    int Nr=r+dy[i];
                    int Nc=c+dx[i];
                    if(Nr>=0&&Nr<N&&Nc>=0&&Nc<M&&Map[Nr][Nc]=='0')
                    {
                        int GID=GIDs[Nr][Nc];
                        if(s.find(GID)==s.end())
                        {
                            s.insert(GID);
                            Res[r][c]+=GroupSize[GID];
                        }
                    }
                }
            }
            Res[r][c]%=10;
        }
    }
    
    for(auto& Row:Res)
    {
        for(auto& Cell:Row)
        {
            cout<<Cell;
        }
        cout<<"\n";
    }
}