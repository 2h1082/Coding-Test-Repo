#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int N=0,M=0;
vector<int> NumsIndex;
vector<int> NumArr;
vector<bool> Visited;
void DFS(int Count)
{
    if(Count==M)
    {
        for(auto& Num :NumsIndex)
        {
            cout<<Num<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=0;i<N;++i)
    {
        if(Visited[i]) continue;
        NumsIndex.push_back(NumArr[i]);
        Visited[i]=true;
        DFS(Count+1);
        NumsIndex.pop_back();
        Visited[i]=false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>M;
    NumsIndex.reserve(M);
    NumArr.assign(N,0);
    Visited.assign(N,false);
    for(int i=0;i<N;++i)
    {
        cin>>NumArr[i];
    }
    sort(NumArr.begin(),NumArr.end());
    DFS(0);
}