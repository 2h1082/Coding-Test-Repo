#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
int N,M;
vector<int> Ack;
vector<int> Parent;
vector<int> SizeArr;
int Find(int A)
{
    if(A==Parent[A]) return A;
    return Parent[A]=Find(Parent[A]);
}
void Union(int A, int B)
{
    int RootA=Find(A);
    int RootB=Find(B);
    if(RootA!=RootB)
    {
        if(SizeArr[RootA]<SizeArr[RootB])
        {
            swap(RootA,RootB);
        }
        Parent[RootB]=RootA;
        SizeArr[RootA]+=SizeArr[RootB];
    }
}
int main()
{
    cin>>N>>M;
    Parent.assign(N+1,0);
    SizeArr.assign(N+1,1);
    iota(Parent.begin(),Parent.end(),0);
    int KnownNum=0;
    cin>>KnownNum;
    if(!KnownNum)
    {
        cout<<M;
        return 0;
    }
    while(KnownNum--)
    {
        int Index=0;
        cin>>Index;
        Ack.push_back(Index);
    }
    vector<vector<int>> Party(M);
    for(int i=0;i<M;++i)
    {
        int Num=0;
        cin>>Num;
        Party[i].assign(Num,0);
        for(int j=0;j<Num;++j)
        {
            cin>>Party[i][j];
            Union(Party[i][0],Party[i][j]);
        }
    }
    for(int i=0;i<Ack.size();++i)
    {
        Union(Ack[0],Ack[i]);
    }
    int KnowRoot=Find(Ack[0]);
    int Count=0;
    for(auto& P : Party)
    {
        if(P.empty()) continue;
        
        int PartyRoot=Find(P[0]);
        if(PartyRoot!=KnowRoot)
        {
            Count++;
        }
    }
    cout<<Count;
}