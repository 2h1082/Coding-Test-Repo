#include <iostream>
#include <queue>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N=0;
    cin>>N;
    
    queue<int> q;
    for(int i=1;i<=N;++i)
    {
        q.push(i);
    }
    while(q.size()>1)
    {
        q.pop();
        int Cur=q.front();
        q.push(Cur);
        q.pop();
    }
    cout<<q.front();
}
