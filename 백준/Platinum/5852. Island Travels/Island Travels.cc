#include "bits/stdc++.h"
using namespace std;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int R,C;
vector<string> A;
bool IsInRange(int y, int x)
{
    return y>=0 && y<R && x>=0 && x<C;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>R>>C;
    
    A.resize(R);
    for(auto& s : A) cin>>s;
    
    // 섬 번호 식별 (BFS)
    vector<vector<int>> Id(R,vector<int>(C,-1));
    int Cnt=0;
    for(int i=0;i<R;++i)
    {
        for(int j=0;j<C;++j)
        {
            if(A[i][j]=='X' && Id[i][j]==-1)
            {
                queue<pair<int,int>> q;
                q.push({i,j});
                Id[i][j]=Cnt;
                while(!q.empty())
                {
                    auto [y,x]=q.front();
                    q.pop();
                    for(int d=0;d<4;++d)
                    {
                        int ny=y+dy[d], nx=x+dx[d];
                        if(!IsInRange(ny,nx)) continue;
                        if(A[ny][nx]=='X' && Id[ny][nx]==-1)
                        {
                            Id[ny][nx]=Cnt;
                            q.push({ny,nx});
                        }
                    }
                }
                ++Cnt;
            }
        }
    }
    
    // 섬 사이 최소 수영 거리 계산
    vector<vector<int>> Dist(Cnt,vector<int>(Cnt,1e9));
    for(int s=0;s<Cnt;++s)
    {
        deque<pair<int,int>> q;
        vector<vector<int>> d(R,vector<int>(C,-1));
        for(int i=0;i<R;++i)
        {
            for(int j=0;j<C;++j)
            {
                if(Id[i][j]==s)
                {
                    q.push_back({i,j});
                    d[i][j]=0;
                }
            }
        }
        
        while(!q.empty())
        {
            auto [y,x]=q.front();
            q.pop_front();
            for(int k=0;k<4;++k)
            {
                int ny=y+dy[k], nx=x+dx[k];
                if(!IsInRange(ny,nx)) continue;
                if(A[ny][nx]=='.') continue;
                
                int Cost=(A[ny][nx]=='S');
                if(d[ny][nx]==-1 || d[ny][nx] > Cost+d[y][x])
                {
                    d[ny][nx]=d[y][x]+Cost;
                    if(Cost)    q.push_back({ny,nx});
                    else        q.push_front({ny,nx});
                    
                    if(A[ny][nx]=='X')
                    {
                        int Nxt=Id[ny][nx];
                        Dist[s][Nxt]=min(Dist[s][Nxt],d[ny][nx]);
                    }
                }
            }
        }
    }
    
    // 비트마스킹 TSP 수행 (최소값 찾기)
    int Full=(1<<Cnt);
    vector<vector<int>> Dp(Full,vector<int>(Cnt,1e9));
    
    for(int i=0;i<Cnt;++i) Dp[1<<i][i]=0;
    
    for(int Mask=0;Mask<Full;++Mask)
    {
        for(int s=0;s<Cnt;++s)
        {
            if(!(Mask&(1<<s)) || Dp[Mask][s]==1e9) continue;

            for(int e=0;e<Cnt;++e)
            {
                if(s==e) continue;
                if(Mask & (1<<e) || Dist[s][e]==1e9) continue;

                int NxtMask=Mask|(1<<e);
                Dp[NxtMask][e]=min(Dp[NxtMask][e],Dp[Mask][s]+Dist[s][e]);
            }
        }
    }
    int Ans=1e9;
    for(int i=0;i<Cnt;++i) Ans=min(Ans,Dp[Full-1][i]);
    cout<<Ans;
}