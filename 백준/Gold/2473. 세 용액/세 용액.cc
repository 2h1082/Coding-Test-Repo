#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N=0;
    cin>>N;
    vector<int> S(N,0);
    for(auto& T : S)
    {
        cin>>T;
    }
    sort(S.begin(),S.end());
    int Idx1,Idx2,Idx3;
    long long Min=LLONG_MAX;
    for(int i=0;i<N-2;++i)
    {
        int L=i+1, R=N-1;
        while(L<R)
        {
            long long Sum=(long long)S[i]+S[L]+S[R];
            if(abs(Sum)<Min)
            {
                Min=abs(Sum);
                Idx1=i; Idx2=L; Idx3=R;
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
                cout<<S[i]<<" "<<S[L]<<" "<<S[R];
                return 0;
            }
        }
    }
    cout<<S[Idx1]<<" "<<S[Idx2]<<" "<<S[Idx3];
}