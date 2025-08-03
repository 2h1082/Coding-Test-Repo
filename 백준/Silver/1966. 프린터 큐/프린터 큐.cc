#include <iostream>
#include <queue>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T=0;
    cin>>T;
    for(int i=0;i<T;++i)
    {
        int N,M;
        cin>>N>>M;
        priority_queue<int> pq;
        queue<pair<int,int>> q;
        for(int j=0;j<N;++j)
        {
            int Num=0;
            cin>>Num;
            pq.push(Num);
            q.push({Num,j});
        }
        int Count=1;
        while(!q.empty())
        {
            auto Cur=q.front();
            if (Cur.first==pq.top())
            {
                q.pop();
                pq.pop();
                if (Cur.second==M) break;
                Count++;
            }
            else
            {
                q.push(q.front());
                q.pop();
            }
        }
        cout<<Count<<"\n";
    }
}