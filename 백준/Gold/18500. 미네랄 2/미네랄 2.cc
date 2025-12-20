#include "bits/stdc++.h"
using namespace std;

int R,C,N,H;
vector<string> A;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
bool IsOutOfRange(int y, int x)
{
    return x>=C || x<0 || y>=R || y<0;
}

void Fall()
{
    vector<vector<bool>> Used(R,vector<bool>(C,false));
    queue<pair<int,int>> q;
    vector<pair<int,int>> InAir;
    
    for(int x=0;x<C;++x)
    {
        if(A[R-1][x]=='x')
        {
            Used[R-1][x]=true;
            q.push({R-1,x});
        }
    }
    
    while(!q.empty())
    {
        auto [y,x]=q.front();
        q.pop();
        for(int d=0;d<4;++d)
        {
            int ny=y+dy[d], nx=x+dx[d];
            if(IsOutOfRange(ny,nx)) continue;
            
            if(!Used[ny][nx] && A[ny][nx]=='x')
            {
                Used[ny][nx]=true;
                q.push({ny,nx});
            }
        }
    }
    
    for(int i=0;i<R;++i)
    {
        for(int j=0;j<C;++j)
        {
            if(Used[i][j]) continue;
            if(A[i][j]=='x')
            {
                InAir.push_back({i,j});
                A[i][j]='.';
            }
        }
    }
    if(InAir.empty()) return;
    
    int Dist=R;
    for(auto [y,x]:InAir)
    {
        int ny=y+1, d=0;
        while(ny<R && A[ny][x]=='.')
        {
            ++ny;
            ++d;
        }
        Dist=min(Dist,d);
    }
    for(auto [y,x] : InAir)
    {
        A[y+Dist][x]='x';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>R>>C;
    A.resize(R);
    for(auto& s : A) cin>>s;
    
    cin>>N;
    bool bIsLeft=true;
    while(N--)
    {
        cin>>H;
        int y=R-H;
        
        if(bIsLeft)
        {
            for(int x=0;x<C;++x)
            {
                if(A[y][x]=='x')
                {
                    A[y][x]='.';
                    break;
                }
            }
        }
        else
        {
            for(int x=C-1;x>=0;--x)
            {
                if(A[y][x]=='x')
                {
                    A[y][x]='.';
                    break;
                }
            }
        }
        Fall();
        bIsLeft=!bIsLeft;
    }
    for(auto& s : A) cout<<s<<'\n';
}