#include <iostream>
#include <unordered_map>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N=0,M=0;
    cin>>N>>M;
    unordered_map<string, string> P;
    for(int i=0;i<N;++i)
    {
        string Site,Pass;
        cin>>Site>>Pass;
        P[Site]=Pass;
    }
    for(int i=0;i<M;++i)
    {
        string Site;
        cin>>Site;
        cout<<P[Site]<<"\n";
    }
}