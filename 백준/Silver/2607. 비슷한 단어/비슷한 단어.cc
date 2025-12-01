#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    
    string B;
    cin>>B;
    
    vector<int> BaseCnt(26,0);
    for(auto c: B) BaseCnt[c-'A']++;
    
    int Ans=0;
    for(int i=1;i<N;++i)
    {
        string S;
        cin>>S;
        
        vector<int> Cnt=BaseCnt;
        int Ex=0, Miss=0;
        
        for(char c : S) Cnt[c-'A']--;
        
        for(int i : Cnt)
        {
            if(i>0) Miss+=i; // Base에 더 많음
            else    Ex-=i;   // 비교 단어에 더 많음
        }
        if(Miss <=1 && Ex<=1) Ans++;
    }
    cout<<Ans;
}