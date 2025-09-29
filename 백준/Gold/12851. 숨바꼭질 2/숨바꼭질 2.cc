#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main()
{
    int N=0,K=0;
    cin>>N>>K;
    queue<int> q;
    vector<int> Time(200001,-1);
    vector<long long> Way(200001,0);
    q.push(N);
    Way[N]=1;
    Time[N]=0;
    while(!q.empty())
    {
        int Cur=q.front();
        q.pop();
        
        for(int Next:{Cur-1,Cur+1,Cur*2})
        {
            if(Next<0||Next>200000) continue;
            if(Time[Next]==-1)
            {
                Time[Next]=Time[Cur]+1;
                Way[Next]=Way[Cur];
                q.push(Next);
            }
            else if(Time[Next]==Time[Cur]+1)
            {
                Way[Next]+=Way[Cur];
            }
        }
    }
    cout<<Time[K]<<"\n"<<Way[K];
}