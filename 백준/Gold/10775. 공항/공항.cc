#include <bits/stdc++.h>

using namespace std;

class U
{
private:  
    vector<int> Root;
public:
    U(int N)
    {
        Root.resize(N);
        iota(Root.begin(),Root.end(),0);
    }
    int Find(int v)
    {
        if(Root[v]==v)
        {
            return v;
        }
        return Root[v]=Find(Root[v]);
    }
    void Union(int v1, int v2)
    {
        int R1=Find(v1);
        int R2=Find(v2);
        
       if (R1!=R2) Root[R2]=R1; 
    }
};
int main()
{
    int G, P;
    cin>>G>>P;
    U Choice(G+1);
    
    int Cnt=0;
    for(int i=0;i<P;++i)
    {
        int Num;
        cin>>Num;
        
        int Remain=Choice.Find(Num);
        if(Remain!=0)
        {
            Cnt++;
            Choice.Union(Remain-1,Remain);
        }
        else
        {
            break;
        }
    }
    cout<<Cnt;
}