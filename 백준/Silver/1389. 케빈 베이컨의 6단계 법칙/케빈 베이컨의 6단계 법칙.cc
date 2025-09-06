#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N=0,M=0;
    cin>>N>>M;
    vector<vector<int>> Connection(N+1);
    while(M--)
    {
        int From, To;
        cin>>From>>To;
        Connection[From].push_back(To);
        Connection[To].push_back(From);
    }
    vector<int> BaconNum(N+1,0);
    for(int i=1;i<=N;++i)
    {
        queue<vector<int>> q;
        vector<bool> Visited(N+1,false);
        q.push({i,i,0});
        Visited[i]=true;
        while(!q.empty())
        {
            int Parent=q.front()[0];
            int Cur=q.front()[1];
            int Depth=q.front()[2];
            q.pop();
            for(auto& Next : Connection[Cur])
            {
                if(!Visited[Next])
                {
                    q.push({Parent,Next,Depth+1});
                    Visited[Next]=true;
                    BaconNum[Parent]+=Depth+1;
                }
            }
        }
    }
    int MinIndex=1;
    int Min=INT_MAX;
    for(int i=1;i<=N;++i)
    {
        if(BaconNum[i]<Min)
        {
            MinIndex=i;
            Min=BaconNum[i];
        }
    }
    cout<<MinIndex;
}