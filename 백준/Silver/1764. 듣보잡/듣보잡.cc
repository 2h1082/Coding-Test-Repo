#include <iostream>
#include <set>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N=0, M=0;
    cin>>N>>M;
    set<string> S;
    for(int i=0;i<N;++i)
    {
        string T;
        cin>>T;
        S.insert(T);
    }
    set<string> Both;
    for(int i=0;i<M;++i)
    {
        string T;
        cin>>T;
        if(S.find(T)!=S.end())
        {
            Both.insert(T);
        }
    }
    cout<<(int)Both.size()<<"\n";
    for(auto& Name:Both)
    {
        cout<<Name<<"\n";
    }
}