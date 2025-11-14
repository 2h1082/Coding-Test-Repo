#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N=0;
    cin>>N;
    vector<int> A(N,0);
    for(auto& a : A) cin>>a;
    
    int B,C;
    cin>>B>>C;
    long long Cnt=0;
    for(auto a : A)
    {
        int Cur=a-B;
        ++Cnt;
        if(Cur<=0) continue;
        Cnt+=(Cur/C);
        if (Cur%C!=0) ++Cnt;
    }
    cout<<Cnt;
}