#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N=0, M=0;
    cin>>N>>M;
    
    vector<string> Board(N);
    for(int i=0;i<N;++i)
    {
        cin>>Board[i];
    }
    int Min=INT_MAX;
    for (int R=0;R<=N-8;++R)
    {
        for (int C=0;C<=M-8;++C)
        {
            int CountW=0, CountB=0;
            for(int i=0;i<8;++i)
            {
                for(int j=0;j<8;++j)
                {
                    char CurColor=Board[R+i][C+j];
                    if((i+j)%2==0)
                    {
                        if(CurColor=='W') CountB++;
                        if(CurColor=='B') CountW++;
                    }
                    else
                    {
                        if(CurColor=='B') CountB++;
                        if(CurColor=='W') CountW++;
                    }
                }
            }
            int Temp=min(CountW,CountB);
            Min=min(Min,Temp);
        }
    }
    cout<<Min;
}
