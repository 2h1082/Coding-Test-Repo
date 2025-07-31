#include <iostream>
#include <map>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N=0,M=0;
    cin>>N;
    map<int,int> Cards;
    for(int i=0;i<N;++i)
    {
        int Num=0;
        cin>>Num;
        Cards[Num]++;
    }
    cin>>M;
    for(int i=0;i<M;++i)
    {
        int Num=0;
        cin>>Num;
        cout<<Cards[Num]<<" ";
    }
}