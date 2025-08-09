#include <iostream>
#include <vector>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N=0,K=0;
    cin>>N>>K;
    vector<int> V(N);
    for(int i=0;i<N;++i)
    {
        cin>>V[i];
    }
    int Count=0;
    for(int i=N-1;i>=0;--i)
    {
        int Cur=K/V[i];
        Count+=Cur;
        if(Cur>0)
        {
            K%=V[i];
            if(K==0) break;
        }
    }
    cout<<Count;
}