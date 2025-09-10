#include <iostream>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N=0, M=0;
    string P;
    cin>>N>>M>>P;
    
    int Count=0;
    int PatternCount=0;
    for (int i=1;i<M-1;++i)
    {
        if (P[i-1]=='I'&&P[i]=='O'&&P[i+1]=='I')
        {
            PatternCount++;
            if (PatternCount>=N)
            {
                Count++;
            }
            i++;
        }
        else
        {
            PatternCount=0;
        }
    }
    
   
    cout<<Count;
}