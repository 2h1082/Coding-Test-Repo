#include "bits/stdc++.h"
using namespace std;

int N;
void Toggle(int Idx, vector<bool>& V)
{
    if(Idx>0)     V[Idx-1]=!V[Idx-1];
    V[Idx]=!V[Idx];
    if(Idx<N-1)   V[Idx+1]=!V[Idx+1];
}
int Simulate(vector<bool> S, vector<bool>& T, bool bFirstPressed)
{
    int Cnt=0;
    
    if(bFirstPressed)
    {
        Toggle(0,S);
        Cnt++;
    }
    
    for(int i=1;i<N;++i)
    {
        if(S[i-1]!=T[i-1])
        {
            Toggle(i,S);
            Cnt++;
        }
    }
    if(S==T) return Cnt;
    return 1e9;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N;
    
    string A, B;
    cin>>A>>B;
    
    vector<bool> S(N),T(N);
    for(int i=0;i<N;++i)
    {
        S[i]=(A[i]=='1');
        T[i]=(B[i]=='1');
    }
    
    int Ans1=Simulate(S,T,false), Ans2=Simulate(S,T,true);
    
    int Ans=min(Ans1,Ans2);
    cout<<(Ans==1e9 ? -1 : Ans);
}