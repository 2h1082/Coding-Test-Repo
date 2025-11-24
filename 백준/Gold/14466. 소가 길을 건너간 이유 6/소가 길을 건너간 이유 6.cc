#include "bits/stdc++.h"
using namespace std;
#define y first
#define x second
using ll=long long;
int dx[4]={0,-1,0,1}; // 상 좌 하 우
int dy[4]={-1,0,1,0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N,K,R;
    cin>>N>>K>>R;
    
    vector<vector<vector<bool>>> Map(N,vector<vector<bool>>(N,vector<bool>(4,false)));
    while(R--)
    {
        int r1,r2,c1,c2;
        cin>>r1>>c1>>r2>>c2;
        for(int i=0;i<4;++i)
        {
            int nr=r1+dy[i], nc=c1+dx[i];
            if(nr==r2 && nc==c2)
            {
                Map[r1-1][c1-1][i]=Map[nr-1][nc-1][(i+2)%4]=true;
                break;
            }
        }
    }
    vector<vector<bool>> Visited(N,vector<bool>(N,false)), Cow(N,vector<bool>(N,false));
    while(K--)
    {
        int r,c;
        cin>>r>>c;
        Cow[r-1][c-1]=true;
    }
    
    vector<int> ComponentCowCnt;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            if(Visited[i][j]) continue;
            
            int Cnt=0;
            queue<pair<int,int>> q;
            q.push({i,j});
            Visited[i][j]=true;
            while(!q.empty())
            {
                int cy=q.front().y, cx=q.front().x;
                q.pop();
                if(Cow[cy][cx]) Cnt++;
                for(int d=0;d<4;++d)
                {
                    if(Map[cy][cx][d]) continue; // 길로만 이동 가능한 방향
                    
                    int ny=cy+dy[d], nx=cx+dx[d];
                    if(ny<0 || ny>=N || nx<0 || nx>=N || Visited[ny][nx]) continue;
                    
                    Visited[ny][nx]=true;
                    q.push({ny,nx});
                }
            }
            ComponentCowCnt.push_back(Cnt);
        }
    }
    ll Ans=0;
    for(int i=0;i<ComponentCowCnt.size();++i)
    {
        for(int j=i+1;j<ComponentCowCnt.size();++j)
        {
            Ans+=(ll)ComponentCowCnt[i] * ComponentCowCnt[j];
        }
    }
    cout<<Ans;
}