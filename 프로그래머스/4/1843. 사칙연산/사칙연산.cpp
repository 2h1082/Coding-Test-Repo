#include <vector>
#include <string>
using namespace std;

int solution(vector<string> Arr)
{
    int N=Arr.size()/2 + 1;
    vector<vector<int>> Max(N,vector<int>(N,-1e9)), Min(N,vector<int>(N,1e9));
    
    // Dp 초기값 세팅
    for(int i=0;i<N;++i)  Max[i][i]=Min[i][i]=stoi(Arr[i*2]);
    
    for(int Len=2;Len<=N;++Len)
    {
        for(int l=0;l<N-Len+1;++l)
        {
            int r=l+Len-1;
            for(int k=l;k<r;++k)
            {
                string Op=Arr[k*2+1];
                
                if(Op=="+")
                {
                    Max[l][r]=max(Max[l][r],Max[l][k]+Max[k+1][r]);
                    Min[l][r]=min(Min[l][r],Min[l][k]+Min[k+1][r]);
                }
                else
                {
                    Max[l][r]=max(Max[l][r],Max[l][k]-Min[k+1][r]);
                    Min[l][r]=min(Min[l][r],Min[l][k]-Max[k+1][r]);
                }
            }
        }
    }
    
    return Max[0][N-1];
}