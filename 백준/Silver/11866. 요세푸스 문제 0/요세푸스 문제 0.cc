#include <iostream>
#include <queue>

using namespace std;
int main()
{
    int N=0,K=0;
    cin>>N>>K;
    
    queue<int> q;
    for(int i=1;i<=N;++i)
    {
        q.push(i);
    }
    int Count=1;
    vector<int> Result;
    while(!q.empty())
    {
        int Cur=q.front();
        q.pop();
        if(Count!=K)
        {
            q.push(Cur);
            Count++;
        }
        else
        {
            Count=1;
            Result.push_back(Cur);
        }
    }
    cout<<"<";
    for(int i=0;i<Result.size();++i)
    {
        cout<<Result[i];
        if(i!=Result.size()-1) cout<<", ";
    }
    cout<<">";
}