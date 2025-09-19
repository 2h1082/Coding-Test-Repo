#include <iostream>
#include <queue>
#include <set>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=0;
    cin>>T;
    while(T--)
    {
        multiset<int> pq;
        int k=0;
        cin>>k;
        while(k--)
        {
            char Command;
            int Num=0;
            cin>>Command>>Num;
            if(Command=='I')
            {
                pq.insert(Num);
            }
            else if(Command=='D'&&pq.size()>0)
            {
                if(Num==-1)
                {
                    pq.erase(pq.begin());
                }
                else if(Num==1)
                {
                    pq.erase(prev(pq.end()));
                }
            }
        }
        if(pq.size()<1)
        {
            cout<<"EMPTY\n";
        }
        else
        {
            cout<<*pq.rbegin()<<" "<<*pq.begin()<<"\n";
        }
    }
}
