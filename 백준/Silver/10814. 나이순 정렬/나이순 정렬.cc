#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N=0;
    cin>>N;
    
    vector<tuple<int,int,string>> User(N);
    for(int i=0;i<N;++i)
    {
        cin>>get<0>(User[i])>>get<2>(User[i]);
        get<1>(User[i])=i;
    }
    sort(User.begin(),User.end(),[&](const tuple<int,int,string>& a, const tuple<int,int,string>& b){
        if(get<0>(a)!=get<0>(b)) return get<0>(a)<get<0>(b);
        return get<1>(a)<get<1>(b);
    });
    for(auto& U : User)
    {
        cout<<get<0>(U)<<" "<<get<2>(U)<<"\n";
    }
}
