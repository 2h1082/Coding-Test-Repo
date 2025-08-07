#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N=0, M=0;
    cin>>N>>M;
    unordered_map<string, string> List;
    for(int i=1;i<=N;++i)
    {
        string Name;
        cin>>Name;
        string Num=to_string(i);
        List[Num]=Name;
        List[Name]=Num;
    }
    for(int i=0;i<M;++i)
    {
        string T;
        cin>>T;
        cout<<List[T]<<"\n";
    }
}