#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;
int main()
{
    int T=0;
    cin>>T;
    for(int i=0;i<T;++i)
    {
        unordered_map<string, int> Clothes;
        set<string> Types;
        int N=0;
        cin>>N;
        for(int j=0;j<N;++j)
        {
            string Name, Type;
            cin>>Name>>Type;
            Clothes[Type]++;
            Types.insert(Type);
        }
        int Answer=1;
        for(auto& C:Types)
        {
            Answer*=Clothes[C]+1;
        }
        cout<<Answer-1<<"\n";
    }
}