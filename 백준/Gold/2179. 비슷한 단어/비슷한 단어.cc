#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, MaxLen=0;
    cin>>N;
    
    vector<string> W(N);
    unordered_map<string,vector<int>> Freq;
    for(int i=0;i<N;++i)
    {
        cin>>W[i];
        
        string Str="";
        for(int j=0;j<W[i].length();++j)
        {
            Str+=W[i][j];
            Freq[Str].push_back(i);
            if(Freq[Str].size()>=2 && MaxLen < Str.length()) MaxLen=Str.length();
        }
    }
    int IdxS=N+1, IdxT=N+1;
    string Key="";
    
    for(const auto& [key, value] : Freq)
    {
        if(value.size()>=2 && key.length()==MaxLen)
        {
            if(value[0] < IdxS)
            {
                IdxS=value[0];
                IdxT=value[1];
                Key=key;
            }
            else if(value[0]==IdxS && value[1] < IdxT)
            {
                IdxT=value[1];
                Key=key;
            }
        }
    }
    cout<<W[Freq[Key][0]]<<'\n'<<W[Freq[Key][1]];
}