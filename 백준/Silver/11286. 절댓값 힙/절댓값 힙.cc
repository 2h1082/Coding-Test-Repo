#include <iostream>
#include <queue>

using namespace std;
int main()
{
    int N=0;
    cin>>N;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> pq;
    while(N--)
    {
        int Num=0;
        cin>>Num;
        if(Num!=0)
        {
            int AbsValue=abs(Num);
            pq.push({AbsValue,Num});
        }
        else
        {
            if (pq.empty())
            {
                cout<<"0"<<"\n";
                continue;
            }
            cout<<pq.top().second<<"\n";
            pq.pop();
        }
    }
}