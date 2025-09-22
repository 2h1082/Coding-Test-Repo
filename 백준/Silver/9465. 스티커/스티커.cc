#include <iostream>
#include <vector>

using namespace std;
int N,T;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>N;
        vector<vector<int>> Stickers(2,vector<int>(N,0));
        for(int i=0;i<2;++i)
        {
            for(int j=0;j<N;++j)
            {
                cin>>Stickers[i][j];
            }   
        }
        
        vector<vector<int>> DP(2,vector<int>(N,0));
        DP[0][0]=Stickers[0][0];
        DP[1][0]=Stickers[1][0];
        int Result=0;
        if(N==1)
        {
            Result=max(Stickers[0][0],Stickers[1][0]);
        }
        else if(N>1)
        {
            DP[0][1]=Stickers[0][1]+Stickers[1][0];
            DP[1][1]=Stickers[0][0]+Stickers[1][1];
            Result=max(DP[0][1],DP[1][1]);
        }
        
        for(int j=2;j<N;++j)
        {
            for (int i=0;i<2;++i)
            {
                int Temp=max(DP[(i+1)%2][j-1],DP[(i+1)%2][j-2]);
                DP[i][j]=Stickers[i][j]+Temp;
                Result=max(Result,DP[i][j]);
            }
        }   
        cout<<Result<<"\n";
    }
}
