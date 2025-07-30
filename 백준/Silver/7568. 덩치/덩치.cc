#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N=0;
    cin>>N;
    vector<vector<int>> Sizes(N,vector<int>(2));
    for(int i=0;i<N;++i)
    {
        cin>>Sizes[i][0]>>Sizes[i][1];
    }
    
    for(int i=0;i<N;++i)
    {
        int Count=1;
        for(int j=0;j<N;++j)
        {
            if(i==j) continue;
            if(Sizes[i][0]<Sizes[j][0] && Sizes[i][1]<Sizes[j][1]) Count++;
        }
        cout<<Count<<" ";
    }
}
