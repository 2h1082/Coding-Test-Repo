#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N=0;
    cin>>N;
    vector<int> Solutions(N,0);
    for(auto& S : Solutions)
    {
        cin>>S;
    }
    int L=0, R=N-1, MinL=0, MinR=0, MinSum=INT_MAX;
    while(L<R)
    {
        int Sum=Solutions[L]+Solutions[R];
        if(abs(Sum)<MinSum)
        {
            MinL=L; MinR=R;
            MinSum=abs(Sum);
        }
        if(Sum>0)
        {
            R--;
        }
        else if(Sum<0)
        {
            L++;
        }
        else
        {
            break;
        }
    }
    cout<<Solutions[MinL]<<" "<<Solutions[MinR];
}