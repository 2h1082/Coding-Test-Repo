#include <bits/stdc++.h>
using namespace std;
// 북 동 남 서
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M;
    cin>>N>>M;
    
    int x=0, y=0, d=0;
    cin>>y>>x>>d;
    
    vector<vector<int>> Map(N,vector<int>(M,0));
    vector<vector<bool>> Dust(N,vector<bool>(M,true));
    for(auto& r : Map)
    {
        for(auto& c : r) 
        {
            cin>>c;
        }
    }
    
    int Cnt=0;
    while(1)
    {
        if(Dust[y][x]) 
        {
            Dust[y][x]=false;
            Cnt++;
        }
        
        bool bExistDust=false;
        for(int i=0;i<4;++i)
        {
            d=(d+3)%4;
            int NxtX=x+dx[d];
            int NxtY=y+dy[d];
            if(NxtX<0||NxtX>=M||NxtY<0||NxtY>=N) continue;
            if(!Map[NxtY][NxtX]&&Dust[NxtY][NxtX]) 
            {
                bExistDust=true;
                break;
            }
        }
        int NxtX=x, NxtY=y;
        if(!bExistDust)
        {
            int BackDir=(d+2)%4;
            NxtX+=dx[BackDir];
            NxtY+=dy[BackDir];            
        }
        else
        {
            NxtX+=dx[d];
            NxtY+=dy[d];
        }
        if(NxtX<0||NxtX>=M||NxtY<0||NxtY>=N||Map[NxtY][NxtX]) break;
        
        x=NxtX;
        y=NxtY;
    }
    cout<<Cnt;
}