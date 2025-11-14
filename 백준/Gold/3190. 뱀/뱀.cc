#include <deque>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N=0,K=0;
vector<vector<int>> Map;
int dx[4]={0,1,0,-1}; //상 우 하 좌
int dy[4]={-1,0,1,0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>K;
    Map.assign(N,vector<int>(N,0));
    while(K--)
    {
        int y, x;
        cin>>y>>x;
        Map[y-1][x-1]=2;
    }
    int L=0;
    cin>>L;
    deque<pair<int,char>> Rotate;
    while(L--)
    {
        int X;
        char C;
        cin>>X>>C;
        Rotate.push_back({X,C});
    }
    Map[0][0]=1;
    int Dir=1, Y=0, X=0, Second=0;
    // 앞쪽 : 머리, 뒤쪽 : 꼬리
    deque<pair<int,int>> Body; // y, x
    Body.push_front({0,0});
    while(1)
    {
        if(!Rotate.empty() && Rotate.front().first==Second)
        {
            if('L'==Rotate.front().second)
            {
                Dir=(Dir-1+4)%4;
            }
            else if('D'==Rotate.front().second)
            {
                Dir=(Dir+1)%4;
            }
            Rotate.pop_front();
        }
        
        int NxtY=Y+dy[Dir], NxtX=X+dx[Dir];
        if(NxtY<0||NxtY>=N||NxtX<0||NxtX>=N||Map[NxtY][NxtX]==1) break;
        
        if(Map[NxtY][NxtX]!=2)
        {
            if(!Body.empty())
            {
                int BackY=Body.back().first, BackX=Body.back().second;
                Map[BackY][BackX]=0;
                Body.pop_back();
            }
        }
        
        Body.push_front({NxtY,NxtX});
        Map[NxtY][NxtX]=1;
        X=NxtX;
        Y=NxtY;
        Second++;
    }
    cout<<Second+1;
}