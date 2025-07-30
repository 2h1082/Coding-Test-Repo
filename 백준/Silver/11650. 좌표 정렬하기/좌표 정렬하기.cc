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
    
    vector<vector<int>> Point(N,vector<int>(2));
    for(int i=0;i<N;++i)
    {
        cin>>Point[i][0]>>Point[i][1];
    }
    sort(Point.begin(),Point.end(),[&](const vector<int>& a, const vector<int>& b){
        if(a[0]!=b[0]) return a[0]<b[0];
        return a[1]<b[1];
    });
    for(auto& P : Point)
    {
        cout<<P[0]<<" "<<P[1]<<"\n";
    }
}
