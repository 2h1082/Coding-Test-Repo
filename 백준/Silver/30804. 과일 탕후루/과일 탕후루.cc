#include <iostream>
#include <map>
#include <vector>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N=0;
    cin>>N;
    vector<int> Stick(N);
    for(int i=0;i<N;++i)
    {
        cin>>Stick[i];
    }
    map<int,int> FruitCount;
    int Max=0;
    int Left=0;
    for(int Right=0;Right<N;++Right)
    {
        FruitCount[Stick[Right]]++;
        while(FruitCount.size()>2)
        {
            FruitCount[Stick[Left]]--;
            if(FruitCount[Stick[Left]]==0)
            {
                FruitCount.erase(Stick[Left]);
            }
            Left++;
        }
        Max=max(Max,Right-Left+1);
    }
    
    cout<<Max;
}