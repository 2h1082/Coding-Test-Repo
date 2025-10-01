#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N=0,M=0;
  
    cin>>N;
    vector<int> A(N,0);
    for(int i=0;i<N;++i)
    {
        cin>>A[i];
    }
    
    cin>>M;
    vector<int> B(M,0);
    for(int i=0;i<M;++i)
    {
        cin>>B[i];
    }
    
    vector<int> Result;
    int IdxA=0,IdxB=0;
    while(IdxA<N&&IdxB<M)
    {
        int MaxVal=-1, MaxIdxA=-1, MaxIdxB=-1;
        
        for(int i=IdxA;i<N;++i)
        {
            for(int j=IdxB;j<M;++j)
            {
                if(A[i]==B[j]&&A[i]>MaxVal)
                {
                    MaxIdxA=i;
                    MaxIdxB=j;
                    MaxVal=A[i];
                }
            }
        }
        if(MaxVal==-1) break;
        IdxA=MaxIdxA+1;
        IdxB=MaxIdxB+1;
        Result.push_back(MaxVal);
    }
    cout<<Result.size()<<"\n";
    for(int& Num:Result)
    {
        cout<<Num<<" ";
    }
    
}