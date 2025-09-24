#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int N=0,M=0;
int MinDist=INT_MAX;
vector<vector<int>> Map;
vector<pair<int,int>> Houses;
vector<pair<int,int>> Chickens;
vector<bool> Selected;

int GetDistance(pair<int,int> From, pair<int,int> To)
{
    return abs(From.first-To.first)+abs(From.second-To.second);
}
void Combination(int Index, int Count)
{
    if(Count==M)
    {
        int TotalDist=0;
        for(auto& House : Houses)
        {
            int TempDist=INT_MAX;
            for(int i=0;i<Chickens.size();++i)
            {
                if(Selected[i])
                {
                    TempDist=min(TempDist,GetDistance(Chickens[i],House));
                }
            }
            TotalDist+=TempDist;
        }
        MinDist=min(MinDist,TotalDist);
        return;
    }
    for(int i=Index;i<Selected.size();++i)
    {
        Selected[i]=true;
        Combination(i+1,Count+1);
        Selected[i]=false;
    }
}
int main()
{
    cin>>N>>M;
    Map.assign(N,vector<int>(N,0));
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            cin>>Map[i][j];
            if(Map[i][j]==1)
            {
                Houses.push_back({j,i}); // x, y
            }
            else if(Map[i][j]==2)
            {
                Chickens.push_back({j,i});
            }
        }
    }
    Selected.assign(Chickens.size(),false);
    Combination(0,0);
    cout<<MinDist;
}