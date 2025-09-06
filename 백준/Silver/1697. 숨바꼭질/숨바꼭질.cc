#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main()
{
    int N=0, K=0;
    cin>>N>>K;
    queue<pair<int,int>> q;
    q.push({N,0});
    vector<bool> Visited(2000001);
    int Second=0;
    while(!q.empty())
    {
        int Cur=q.front().first;
        int Time=q.front().second;
        q.pop();
        if(Cur==K)
        {
            Second=Time;
            break;
        }
        int NextTime=Time+1;
        if(!Visited[Cur-1]&&Cur-1>=0)
        {
            q.push({Cur-1,NextTime});
            Visited[Cur-1]=true;
        }
        if(!Visited[Cur+1]&&Cur+1<=200000)
        {
            q.push({Cur+1,NextTime});
            Visited[Cur+1]=true;
        }
        if(!Visited[Cur*2]&&Cur*2<=200000)
        {
            q.push({Cur*2,NextTime});
            Visited[Cur*2]=true;
        }
    }
    cout<<Second;
}