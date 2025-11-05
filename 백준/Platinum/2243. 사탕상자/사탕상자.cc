#include <bits/stdc++.h>

using namespace std;

vector<int> Tree;
int Query(int Cur, int S, int E, int Order)
{
    if(S==E) return S;
    
    int Mid=(S+E)/2;
    
    if(Tree[Cur*2]>=Order)
    {
        return Query(Cur*2,S,Mid,Order);
    }
    else
    {
        return Query(Cur*2+1,Mid+1,E,Order-Tree[Cur*2]);
    }
}
void Update(int Cur, int S, int E, int Idx, int Diff)
{
    if(Idx<S||Idx>E) return;
    Tree[Cur]+=Diff;
    if(S==E) return;
    
    int Mid=(S+E)/2;
    Update(Cur*2,S,Mid,Idx,Diff);
    Update(Cur*2+1,Mid+1,E,Idx,Diff);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N=0, A=0,B=0,C=0;
    int Max=1000000;
    cin>>N;
    Tree.assign(4*Max,0);
    while(N--)
    {
        cin>>A;
        if(A==1)
        {
            cin>>B;
            int Order=Query(1,1,Max,B);
            cout<<Order<<'\n';
            Update(1,1,Max,Order,-1);
        }
        else
        {
            cin>>B>>C;
            Update(1,1,Max,B,C);
        }
    }
}