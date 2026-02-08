#include "bits/stdc++.h"
using namespace std;
using ll=long long;

int A,B,C;
int Mul(int A, int B)
{
    if(B==1) return A%C;
    ll Half=Mul(A,B/2)%C, Ans=Half*Half%C;
    
    if(B%2) return Ans*A%C;
    else    return Ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>A>>B>>C;
    cout<<Mul(A,B);
}