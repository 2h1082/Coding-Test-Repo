#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef pair<int,int> Edge;
int main()
{
    string s1, s2;
    cin>>s1>>s2;
    int Len1=s1.length(), Len2=s2.length();
    vector<vector<int>> DP(Len1+1,vector<int>(Len2+1,0));
    vector<vector<Edge>> Prev(Len1+1,vector<Edge>(Len2+1));
    
    DP[0][0]=DP[1][0]=DP[0][1]=0;
    Edge FinalIdx;
    int Max=0;
    for(int i=1;i<=Len1;++i)
    {
        for(int j=1;j<=Len2;++j)
        {
            if(s1[i-1]==s2[j-1])
            {
                DP[i][j]=DP[i-1][j-1]+1;
            }
            else
            {
                DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
            }
        }
    }
    int i=Len1,j=Len2;
    string Res;
    while(i>0&&j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            Res=s1[i-1]+Res;
            i--;
            j--;
        }
        else if(DP[i-1][j]>DP[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout<<DP[Len1][Len2]<<"\n"<<Res;
} 