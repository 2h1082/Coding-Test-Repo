#include "bits/stdc++.h"
using namespace std;

int N;
vector<pair<int,int>> Ans;
void Move(int From, int Temp, int To, int Num)
{
    if(Num==1)
    {
        Ans.push_back({From,To});
        return;
    }
    Move(From,To,Temp,Num-1);
    Ans.push_back({From,To});
    Move(Temp,From,To,Num-1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N;
    Move(1,2,3,N);
    cout<<Ans.size()<<'\n';
    for(auto [F,T] : Ans) cout<<F<<' '<<T<<'\n';
}