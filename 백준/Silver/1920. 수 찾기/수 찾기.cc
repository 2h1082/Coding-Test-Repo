#include <iostream>
#include <set>


using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N=0,M=0;
    cin>>N;
    set<int> A;
    for(int i=0;i<N;++i)
    {
        int Temp=0;
        cin>>Temp;
        A.insert(Temp);
    }
    cin>>M;
    for(int i=0;i<M;++i)
    {
        int Num=0;
        cin>>Num;
        int Result=0;
        if(A.find(Num)!=A.end()) Result=1;
        cout<<Result<<"\n";
    }
}
