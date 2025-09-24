#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main()
{
    int N,K;
    cin>>N>>K;
    deque<int> q;
    vector<int> Cost(200001,INT_MAX);
    q.push_back(N);
    Cost[N]=0;
    while(!q.empty())
    {
        int Cur=q.front();
        q.pop_front();
        if(Cur==K)
        {
            cout<<Cost[Cur];
            break;
        }
        int Plus=Cur+1;
        int Minus=Cur-1;
        int Double=Cur*2;
        if(Double<=200000&&Cost[Cur]<Cost[Double])
        {
            q.push_front(Double);
            Cost[Double]=Cost[Cur];
        }
        if(Plus>=0&&Cost[Cur]+1<Cost[Plus])
        {
            q.push_back(Plus);
            Cost[Plus]=Cost[Cur]+1;
        }
        if(Minus>=0&&Cost[Cur]+1<Cost[Minus])
        {
            q.push_back(Minus);
            Cost[Minus]=Cost[Cur]+1;
        }
    }
}