#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
long long V=0, Max=0;
vector<vector<pair<int,int>>> Tree;
vector<bool> Visited;
long long ComputeRadius(int Cur, int Prev)
{
    long long Radius1=0, Radius2=0;
    for(auto Info : Tree[Cur])
    {
        //auto [W,To]=Info;
        int W=Info.first, To=Info.second;
        if(Visited[To]) continue;
        Visited[To]=true;
        long long CurCost=W+ComputeRadius(To,Cur);
        if(CurCost>Radius2)
        {
            Radius1=max(Radius1,Radius2);
            Radius2=CurCost;
        }
        else if(CurCost>Radius1)
        {
            Radius1=CurCost;
        }
    }
    Max=max(Max,Radius1+Radius2);
    return Radius2;
}
int main()
{
    cin>>V;
    Tree.assign(V+1,vector<pair<int,int>>());
    Visited.assign(V+1,false);
    for(int i=0;i<V;++i)
    {
        int From=0, Weight=0, To=0;
        cin>>From;
        while(1)
        {
            cin>>To;
            if(To==-1) break;
            cin>>Weight;
            Tree[From].push_back({Weight,To});
            Tree[To].push_back({Weight,From});
        }
    }
    Visited[1]=true;
    ComputeRadius(1,0);
    cout<<Max;
}