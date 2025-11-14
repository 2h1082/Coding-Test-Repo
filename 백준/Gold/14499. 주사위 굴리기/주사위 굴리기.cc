#include <bits/stdc++.h>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};

void Roll(vector<int>& D, int Dir)
{
    // 윗, 아래, 북, 남, 동, 서 (0~5)
    if(Dir==0) // 동
    {
        int Temp=D[0];
        D[0]=D[5];
        D[5]=D[1];
        D[1]=D[4];            
        D[4]=Temp;
    }
    else if(Dir==1) // 서
    {
        int Temp=D[0];
        D[0]=D[4];
        D[4]=D[1];
        D[1]=D[5];            
        D[5]=Temp;
    }
    else if(Dir==2) // 북
    {
        int Temp=D[0];
        D[0]=D[3];
        D[3]=D[1];
        D[1]=D[2];            
        D[2]=Temp;
    }
    else if(Dir==3) // 남
    {
        int Temp=D[0];
        D[0]=D[2];
        D[2]=D[1];
        D[1]=D[3];            
        D[3]=Temp;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N=0,M=0, Sx, Sy, K=0;
    cin>>N>>M>>Sy>>Sx>>K;
    
    vector<vector<int>> Map(N,vector<int>(M,0));
    for(auto& row : Map)
    {
        for(auto& c : row) cin>>c;
    }
    // 윗면, 아랫면, 북, 남, 동, 서
    vector<int> Dice(6,0);
    int CurX=Sx, CurY=Sy;
    while(K--)
    {
        int Dir=0;
        cin>>Dir;
        --Dir;
        int NxtX=CurX+dx[Dir], NxtY=CurY+dy[Dir];
        if(NxtX<0||NxtX>=M||NxtY<0||NxtY>=N)
        {
            continue;
        } 
        
        Roll(Dice,Dir);
        if(Map[NxtY][NxtX]==0)
        {
            Map[NxtY][NxtX]=Dice[1];
        }
        else
        {
            Dice[1]=Map[NxtY][NxtX];
            Map[NxtY][NxtX]=0;
        }
        cout<<Dice[0]<<'\n';
        CurX=NxtX;
        CurY=NxtY;
    }
}