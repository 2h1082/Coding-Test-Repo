#include <vector>
#include <string>
using namespace std;

int solution(vector<string> Arr)
{
    int N=Arr.size()/2 + 1;
    vector<vector<int>> Min(N,vector<int>(N,1e9)), Max(N,vector<int>(N,-1e9));
    for(int i=0;i<N;++i) Min[i][i]=Max[i][i]=stoi(Arr[i*2]);
    
    for(int Len=2;Len<=N;++Len)
    {
        for(int S=0;S<N-Len+1;++S)
        {
            int E=S+Len-1;
            for(int M=S;M<E;++M)
            {
                char Op=Arr[2*M+1][0];
                if(Op=='+')  
                {
                    Max[S][E]=max(Max[S][E], Max[S][M]+Max[M+1][E]);
                    Min[S][E]=min(Min[S][E], Min[S][M]+Min[M+1][E]);
                }
                else            
                {
                    Max[S][E]=max(Max[S][E], Max[S][M]-Min[M+1][E]);
                    Min[S][E]=min(Min[S][E], Min[S][M]-Max[M+1][E]);
                }
            }
        }
    }
    
    
    return Max[0][N-1];
}