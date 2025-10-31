#include <bits/stdc++.h>

using namespace std;

vector<int> GetPi(string P)
{
    int M=P.size();
    vector<int> Pi(M,0);
    int j=0;
    for(int i=1;i<M;++i)
    {
        while(j>0&&P[i]!=P[j]) j=Pi[j-1];
        if(P[i]==P[j]) Pi[i]=++j;
    }
    return Pi;
}

vector<int> KMP(string T, string P)
{
    vector<int> Pi=GetPi(P);
    vector<int> Res;
    int N=T.size(), M=P.size(), j=0;
    
    for(int i=0;i<N;++i)
    {
        while(j>0&&T[i]!=P[j]) j=Pi[j-1];
        if(T[i]==P[j])
        {
            if(j==M-1)
            {
                Res.push_back(i-M+2);
                j=Pi[j];
            }
            else ++j;
        }
    }
    return Res;
}

int main()
{
    string T,P;
    getline(cin,T);
    getline(cin,P);
    vector<int> Res=KMP(T,P);
    cout<<Res.size()<<"\n";
    for(auto& r : Res)
    {
        cout<<r<<" ";
    }
}