#include <iostream>
#include <vector>

using namespace std;
int N=0,M=0;
vector<int> Nums;
void DFS(int Index, int Count)
{
    if(Count==M)
    {
        for (auto& Num:Nums)
        {
            cout<<Num<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=Index;i<=N;++i)
    {
        Nums.push_back(i);
        DFS(i+1,Count+1);
        Nums.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>M;
    Nums.reserve(M);
    DFS(1,0);
}