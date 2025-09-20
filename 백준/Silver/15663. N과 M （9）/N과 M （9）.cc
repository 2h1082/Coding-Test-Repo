#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N=0,M=0;
vector<int> Nums;
vector<int> Result;
vector<bool> Visited;
void DFS(int Count)
{
    if(Count==M)
    {
        for(auto& Num : Result)
        {
            cout<<Num<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=0;i<N;++i)
    {
        if(Visited[i]) continue;
        if(i>0&&Nums[i-1]==Nums[i]&&!Visited[i-1])
        {
            continue;
        }
        Visited[i]=true;
        Result.push_back(Nums[i]);
        DFS(Count+1);
        Result.pop_back();
        Visited[i]=false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>M;
    Nums.assign(N,0);
    Visited.assign(N,false);
    Result.reserve(M);
    for(int i=0;i<N;++i)
    {
        cin>>Nums[i];
    }
    sort(Nums.begin(),Nums.end());
    DFS(0);
}