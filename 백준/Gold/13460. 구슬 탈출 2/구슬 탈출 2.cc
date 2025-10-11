#include <bits/stdc++.h>

using namespace std;
int N,M;
vector<string> Board;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
struct State
{
    int RY, RX;
    int BY, BX;
    int Count;
};
void MoveBall(int& Y, int& X, int Dir, int OtherY, int OtherX)
{
    while(1)
    {
        int NextY=Y+dy[Dir], NextX=X+dx[Dir];
        
        if(NextY<0||NextY>=N||NextX<0||NextX>=M) break;
        if(Board[NextY][NextX]=='O')
        {
            Y=NextY;
            X=NextX;
            break;
        }
        
        if(Board[NextY][NextX]=='#') break;
        if(NextY==OtherY&&NextX==OtherX) break;
        
        Y=NextY;
        X=NextX;
    }
}
int main()
{
    cin>>N>>M;
    Board.assign(N,string());
    int StartYB, StartXB;
    int StartYR, StartXR;
    for(int i=0;i<N;++i)
    {
        cin>>Board[i];
        for(int j=0;j<M;++j)
        {
            if(Board[i][j]=='B')
            {
                StartYB=i; StartXB=j;
            }
            if(Board[i][j]=='R') 
            {
                StartYR=i; StartXR=j;
            }
        }
    }
    queue<State> q;
    vector<vector<vector<vector<bool>>>> Visited(N,vector<vector<vector<bool>>>(M, vector<vector<bool>>(N, vector<bool>(M,false))));
    
    q.push({StartYR,StartXR,StartYB,StartXB,0});
    Visited[StartYR][StartXR][StartYB][StartXB]=true;
    while(!q.empty())
    {
        State Cur=q.front();
        q.pop();
        
        if(Cur.Count>=10) break;
        
        for(int i=0;i<4;++i)
        {
            int NRY=Cur.RY, NRX=Cur.RX;
            int NBY=Cur.BY, NBX=Cur.BX;
            if(i==0)
            {
                if(Cur.RY<Cur.BY)
                {
                    MoveBall(NRY,NRX,i,NBY,NBX);
                    MoveBall(NBY,NBX,i,NRY,NRX);
                }
                else
                {
                    MoveBall(NBY,NBX,i,NRY,NRX);
                    MoveBall(NRY,NRX,i,NBY,NBX);
                }
            }
            else if(i==1)
            {
                if(Cur.BY<Cur.RY)
                {
                    MoveBall(NRY,NRX,i,NBY,NBX);
                    MoveBall(NBY,NBX,i,NRY,NRX);
                }
                else
                {
                    MoveBall(NBY,NBX,i,NRY,NRX);
                    MoveBall(NRY,NRX,i,NBY,NBX);
                }
            }
            else if(i==2)
            {
                if(Cur.RX<Cur.BX)
                {
                    MoveBall(NRY,NRX,i,NBY,NBX);
                    MoveBall(NBY,NBX,i,NRY,NRX);
                }
                else
                {
                    MoveBall(NBY,NBX,i,NRY,NRX);
                    MoveBall(NRY,NRX,i,NBY,NBX);
                }
            }
            else
            {
                if(Cur.BX<Cur.RX)
                {
                    MoveBall(NRY,NRX,i,NBY,NBX);
                    MoveBall(NBY,NBX,i,NRY,NRX);
                }
                else
                {
                    MoveBall(NBY,NBX,i,NRY,NRX);
                    MoveBall(NRY,NRX,i,NBY,NBX);
                }
            }
            bool bIsBlueGoal=(Board[NBY][NBX]=='O');
            bool bIsRedGoal=(Board[NRY][NRX]=='O');
            if(bIsBlueGoal) continue;
            if(bIsRedGoal)
            {
                cout<<Cur.Count+1;
                return 0;
            }
            if(!Visited[NRY][NRX][NBY][NBX])
            {
                Visited[NRY][NRX][NBY][NBX]=true;
                q.push({NRY,NRX,NBY,NBX,Cur.Count+1});
            }
        }
    }
    cout<<"-1";
}