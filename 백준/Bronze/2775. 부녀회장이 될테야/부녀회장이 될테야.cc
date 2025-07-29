#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int T=0;
    cin>>T;
    int MaxNum=14;
    vector<vector<int>> Count(MaxNum+1,vector<int>(MaxNum+1,0));
    
    for (int i = 1; i <= MaxNum; ++i) 
    {
        Count[0][i] = i;
    }
    for(int i=1;i<=MaxNum;++i)
    {
        for(int j=1;j<=MaxNum;++j)
        {
            if(j==1) Count[i][j]=1;
            else
            {
                Count[i][j]=Count[i][j-1]+Count[i-1][j];
            }
        }
    }
    for (int i=0;i<T;++i)
    {
        int k=0,n=0,answer=0;;
        cin>>k>>n;
        
        cout<<Count[k][n]<<endl;
    }
}