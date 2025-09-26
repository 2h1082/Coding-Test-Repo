#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N=0;
vector<vector<pair<int,int>>> Tree;
vector<bool> Visited;
long long Max=0;
long long DFS(int Cur)
{
    vector<long long> Dist;
    long long Radius1=0, Radius2=0;
    for(auto Next : Tree[Cur])
    {
        if(Visited[Next.second]) continue;
        Visited[Next.second]=true;
        long long TempRadius=DFS(Next.second)+Next.first;
        Visited[Next.second]=false;
        if(TempRadius>Radius2)
        {
            Radius1=max(Radius1,Radius2);
            Radius2=TempRadius;
        }
        else
        {
            Radius1=max(Radius1,TempRadius);
        }
    }
    Max=max(Max,Radius1+Radius2);
    return Radius2;
}
int main()
{
    cin>>N;
    Tree.assign(N+1,vector<pair<int,int>>());
    for(int i=1;i<N;++i)
    {
        int From,To,Weight;
        cin>>From>>To>>Weight;
        Tree[From].push_back({Weight,To});
        Tree[To].push_back({Weight,From});
    }
    Visited.assign(N+1,false);
    Visited[1]=true;
    DFS(1);
    cout<<Max;
}
