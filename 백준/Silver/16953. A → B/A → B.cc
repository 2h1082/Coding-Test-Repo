#include <iostream>
#include <vector>
#include <queue>

using namespace std;
long A,B;
int main()
{
    cin>>A>>B;
    queue<pair<long,long>> q;
    q.push({A,0});
    long Result=0;
    while(!q.empty())
    {
        long Cur=q.front().first;
        long Count=q.front().second;
        q.pop();
        if(Cur==B)
        {
            Result=Count+1;
            break;
        }
        long Option1=Cur*2;
        long Option2=Cur*10+1;
        if(Option1<=B)
        {
            q.push({Option1,Count+1});
        }
        if(Option2<=B)
        {
            q.push({Option2,Count+1});
        }
    }
    if(Result>1)
    {
        cout<<Result;
    }
    else
    {
        cout<<"-1";
    }
}