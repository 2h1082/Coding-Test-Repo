#include <iostream>
#include <vector>

using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int R=0,C=0,T=0;
int DustCount=0;
vector<vector<int>> Room;
vector<int> AirPosition;
void ExpandDust(vector<vector<int>> Origin)
{
    for(int y=0;y<R;++y)
    {
        for(int x=0;x<C;++x)
        {
            if(Origin[y][x]<5) continue;
            int Amount=Origin[y][x]/5;
            for(int k=0;k<4;++k)
            {
                int NextX=x+dx[k];
                int NextY=y+dy[k];
                if(NextX>=0&&NextX<C&&NextY>=0&&NextY<R&&Room[NextY][NextX]!=-1)
                {
                    Room[NextY][NextX]+=Amount;
                    Room[y][x]-=Amount;
                }
            }
        }
    }
}
void ActivateAirMachine()
{
    int UpperY=AirPosition[0]-1>=0?AirPosition[0]-1:0;
    int LowerY=AirPosition[1]+1<R?AirPosition[1]+1:R-1;
    
    DustCount-=Room[UpperY][0]+Room[LowerY][0];
    
    for (int y=UpperY;y>0;--y)           Room[y][0]=Room[y-1][0];
    for (int x=0;x<C-1;++x)              Room[0][x]=Room[0][x+1];
    for (int y=0;y<AirPosition[0];++y)   Room[y][C-1]=Room[y+1][C-1];
    for (int x=C-1;x>1;--x)              Room[AirPosition[0]][x]=Room[AirPosition[0]][x-1];
    Room[AirPosition[0]][1]=0;
    
    for (int y=LowerY;y<R-1;++y)         Room[y][0]=Room[y+1][0];
    for (int x=0;x<C-1;++x)              Room[R-1][x]=Room[R-1][x+1];
    for (int y=R-1;y>AirPosition[1];--y) Room[y][C-1]=Room[y-1][C-1];
    for (int x=C-1;x>1;--x)              Room[AirPosition[1]][x]=Room[AirPosition[1]][x-1];
    Room[AirPosition[1]][1]=0;
}
int main()
{
    cin>>R>>C>>T;
    Room.assign(R,vector<int>(C,0));
    for(int i=0;i<R;++i)
    {
        for(int j=0;j<C;++j)
        {
            cin>>Room[i][j];
            if(Room[i][j]==-1)
            {
                AirPosition.push_back(i); //Y
            }
            else if(Room[i][j])
            {
                DustCount+=Room[i][j];
            }
        }
    }
    while(T--)
    {
        ExpandDust(Room);
        ActivateAirMachine();
    }
    
    cout<<DustCount;
}