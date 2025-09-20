#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int N,M;
vector<int> Nums;
vector<int> Result;
map<int,int> StartCount;
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
        if(i>0&&Nums[i-1]==Nums[i]&&StartCount[Nums[i-1]]
            || (!Result.empty() && Result.back()>Nums[i])) continue;
        Result.push_back(Nums[i]);
        StartCount[Nums[i]]++;
        DFS(Count+1);
        Result.pop_back();
    }
}
int main()
{
    cin>>N>>M;
    Nums.assign(N,0);
    Result.reserve(N);
    for(int i=0;i<N;++i)
    {
        cin>>Nums[i];
    }
    sort(Nums.begin(),Nums.end());
    DFS(0);
}