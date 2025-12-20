#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string S;
    int N;
    cin>>N>>S;
    
    vector<int> Num;
    vector<char> Op;
    
    for(int i=0;i<S.size();++i)
    {
        if(i%2) Op.push_back(S[i]);
        else    Num.push_back(S[i]-'0');
    }
    
    int M=Num.size();
    vector<vector<int>> Max(M,vector<int>(M,-1e9)), Min(M,vector<int>(M,1e9));
    for(int i=0;i<M;++i) Max[i][i]=Min[i][i]=Num[i];
    
    for(int Len=2;Len<=M;++Len)
    {
        for(int l=0;l+Len-1<M;++l)
        {
            int r=l+Len-1;
            for(int k=l;k<r;++k)
            {
                char op=Op[k];
                for(int a : {Min[l][k],Max[l][k]})
                {
                    for(int b : {Min[k+1][r],Max[k+1][r]})
                    {
                        int v;
                        if(op=='+')      v=a+b;
                        else if(op=='-') v=a-b;
                        else             v=a*b;
                        Min[l][r]=min(Min[l][r],v);
                        Max[l][r]=max(Max[l][r],v);
                    }
                }
            }
        }
    }
    cout<<Max[0][M-1];
}