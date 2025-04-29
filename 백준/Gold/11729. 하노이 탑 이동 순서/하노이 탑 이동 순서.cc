#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int,int>> l;

int Hanoi(int start, int temp, int end, int n)
{
    if (n==1)
    {
        l.push_back({start,end});
        return 1;
    }
    int count=0;
    count+=Hanoi(start,end,temp,n-1);
    l.push_back({start,end});
    count++;
    return count+Hanoi(temp,start,end,n-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    cout<<Hanoi(1,2,3,n)<<"\n";
    for (auto a:l)
    {
        cout<<a.first<<" "<<a.second<<"\n";
    }
    return 0;
}