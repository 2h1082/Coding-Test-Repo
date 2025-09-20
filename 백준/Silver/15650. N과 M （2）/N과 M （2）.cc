#include <iostream>
#include <vector>

using namespace std;
int N=0,M=0;
void DFS(int Index, int Count,vector<int> Nums)
{
    Nums.push_back(Index);
    if(Count==M)
    {
        for (auto& Num:Nums)
        {
            cout<<Num<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=Index+1;i<=N;++i)
    {
        DFS(i,Count+1,Nums);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>M;
    for(int i=1;i<=N-M+1;++i)
    {
        DFS(i,1,vector<int>());
    }
    
}