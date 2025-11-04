#include <bits/stdc++.h>

using namespace std;

vector<int> Tree,Num;
int Build(int Cur, int S, int E)
{
    if(S==E) return Tree[Cur]=S;
    
    int Mid=(S+E)/2;
    int Idx1=Build(Cur*2,S,Mid);
    int Idx2=Build(Cur*2+1,Mid+1,E);
    return Tree[Cur]=(Num[Idx1]<=Num[Idx2]) ? Idx1 : Idx2;
}

int Query(int Cur, int S, int E, int L, int R)
{
    if(L>E || R<S) return 0;
    if(L<=S&&E<=R) return Tree[Cur];
    
    int Mid=(S+E)/2;
    int Idx1=Query(Cur*2,S,Mid,L,R);
    int Idx2=Query(Cur*2+1,Mid+1,E,L,R);
    return (Num[Idx1]<=Num[Idx2]) ? Idx1 : Idx2;
}

void UpdateNode(int Cur, int S, int E, int Idx, int NewVal)
{
    if(Idx<S || Idx>E) return;
    if(S==E)
    {
        Num[Idx]=NewVal;
        return;
    }
    int Mid=(S+E)/2;
    UpdateNode(Cur*2,S,Mid,Idx,NewVal);
    UpdateNode(Cur*2+1,Mid+1,E,Idx,NewVal);
    int Idx1=Tree[Cur*2], Idx2=Tree[Cur*2+1];
    Tree[Cur]= (Num[Idx1]<=Num[Idx2]) ? Idx1 : Idx2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N=0;
    cin>>N;
    Num.assign(N+1,INT_MAX);
    Tree.assign(4*N,0);
    for(int i=1;i<=N;++i)
    {
        cin>>Num[i];
    }
    Build(1,1,N);
    int M=0;
    cin>>M;
    while(M--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1)
        {
            UpdateNode(1,1,N,b,c);
        }
        else
        {
            cout<<Query(1,1,N,b,c)<<"\n";
        }
    }
}