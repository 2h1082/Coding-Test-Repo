#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n=0;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int CurrentMax=v[0];
    int Max=v[0];
    for (int i=1;i<n;i++)
    {
        CurrentMax=max(CurrentMax+v[i],v[i]);
        Max=max(Max,CurrentMax);
    }
    cout<<Max;
    return 0;
}