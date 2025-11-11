#include <bits/stdc++.h>
using namespace std;
using ll=long long;

vector<int> Seg;
void Update(int Node, int S, int E, int Idx, int Diff)
{
    if(Idx<S || Idx>E) return;
    Seg[Node]+=Diff;
    if(S==E) return;
    int Mid=(S+E)/2;
    Update(Node*2,S,Mid,Idx,Diff);
    Update(Node*2+1,Mid+1,E,Idx,Diff);
}
int Query(int Node, int S, int E, int L, int R)
{
    if(L>E || R<S) return 0;
    if(L<=S&&E<=R) return Seg[Node];
    int Mid=(S+E)/2;
    return Query(Node*2,S,Mid,L,R)+Query(Node*2+1,Mid+1,E,L,R);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T,N,M;
    cin>>T;
    while(T--)
    {
        cin>>N>>M;
        int Size=N+M;
        Seg.assign(4*Size,0);
        
        vector<int> Pos(N+1);
        // 배열의 1~M까지의 인덱스를 비워두고 M+1부터 맨위부터 채우기
        for(int i=1;i<=N;++i)
        {
            Pos[i]=M+i;
            Update(1,1,Size,Pos[i],1);
        }
        int Top=M;
        for(int i=0;i<M;++i)
        {
            int x; 
            cin>>x;
            // 현재 꺼내는 x 위의 DVD 개수 카운팅
            int Above=Query(1,1,Size,1,Pos[x]-1);
            cout<<Above<<" ";
            
            Update(1,1,Size,Pos[x],-1);         
            Pos[x]=Top;
            Update(1,1,Size,Pos[x],1);
            --Top;
        }
        cout<<'\n';
    }
}