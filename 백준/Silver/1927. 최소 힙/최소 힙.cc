#include <iostream>
#include <queue>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N=0;
    cin>>N;
    priority_queue<int,vector<int>,greater<>> pq;
    while(N--)
    {
        int Com=0;
        cin>>Com;
        int Result=0;
        if(Com==0)
        {
            if(!pq.empty())
            {
                Result=pq.top();
                pq.pop();
            }
            cout<<Result<<"\n";
        }
        else
        {
            pq.push(Com);
        }
    }
}