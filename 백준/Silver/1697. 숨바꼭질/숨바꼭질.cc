#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,K;
    cin>>N>>K;
    
    queue<int> Q;
    vector<int> Used(200001,0);
    Used[N]=1;
    Q.push(N);
    while(!Q.empty())
    {
        int Cur=Q.front();
        Q.pop();
        int Minus=Cur-1, Plus=Cur+1, Mul=Cur*2;
        if(Minus>=0 && !Used[Minus])
        {
            Used[Minus]=Used[Cur]+1;
            Q.push(Minus);
        }
        if(Plus<100001 && !Used[Plus])
        {
            Used[Plus]=Used[Cur]+1;
            Q.push(Plus);
        }
        if(Mul<200001 && !Used[Mul])
        {
            Used[Mul]=Used[Cur]+1;
            Q.push(Mul);
        }
        if(Minus==K || Plus==K || Mul==K) break;
    }
    cout<<Used[K]-1;
}