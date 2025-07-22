#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int T=0;
    cin>>T;
    
    for(int i=0;i<T;++i)
    {
        int N=0;
        string S;
        cin>>N>>S;
        for(auto& c : S)
        {
            for(int j=0;j<N;++j) cout<<c;
        }
        cout<<"\n";
    }
}