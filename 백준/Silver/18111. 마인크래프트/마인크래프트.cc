#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N=0,M=0,B=0;
    cin>>N>>M>>B;
    
    vector<vector<int>> Blocks(N,vector<int>(M));
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            cin>>Blocks[i][j];
        }
    }
    int MaxHeight=0,Count=INT_MAX;
    for(int Target=0;Target<257;++Target)
    {
        int Remain=B, TimeCost=0;
        for(auto& Row:Blocks)
        {
            for(auto& Cell:Row)
            {
                int Diff=Cell-Target;
                if(Diff>0)
                {
                    TimeCost+=Diff*2;
                    Remain+=Diff;
                }
                else
                {
                    TimeCost-=Diff;
                    Remain+=Diff;
                }
            }
        }
        if(Remain>=0)
        {
            MaxHeight = Count>=TimeCost ? Target : MaxHeight;
            Count=min(Count,TimeCost);
        }
    }
    cout<<Count<<" "<<MaxHeight;
}