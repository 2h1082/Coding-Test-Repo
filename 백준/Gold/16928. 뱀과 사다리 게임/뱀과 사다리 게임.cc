#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N=0,M=0;
    cin>>N>>M;
    vector<int> Board(101,0);
    vector<int> MinCount(101,INT_MAX);
    int From=0,To=0;
    for(int i=0;i<N;++i)
    {
        cin>>From>>To;
        Board[From]=To;
    }
    for(int j=0;j<M;++j)
    {
        cin>>From>>To;
        Board[From]=To;
    }
    queue<vector<int>> q;
    q.push({1,0});
    int Result=0;
    while(!q.empty())
    {
        int Cur=q.front()[0];
        int Count=q.front()[1];
        if(Cur==100)
        {
            Result=Count;
            break;
        }
        q.pop();
        for(int i=1;i<7;++i)
        {
            int Next=Cur+i;
            if(Next<=100)
            {
                Next=Board[Next]==0?Next:Board[Next];
                if(MinCount[Next]>Count+1)
                {
                    MinCount[Next]=Count+1;
                    q.push({Next,Count+1});
                }
            }
        }
    }
    cout<<Result;
}