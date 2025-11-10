#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int C, N, Q;
set<string> Nick;
struct Trie
{
    bool bIsEnd;
    map<char, Trie*> Nxt;
    Trie()
    {
        bIsEnd=false;
    }
    void Insert(const string& S)
    {
        Trie* Cur=this;
        for(auto c : S)
        {
            if(!Cur->Nxt[c]) Cur->Nxt[c]=new Trie();
            Cur=Cur->Nxt[c];
        }
        Cur->bIsEnd=true;
    }
    int CheckWord(const string& S)
    {
        Trie* Cur=this;
        for(int i=0;i<S.size()-1;++i)
        {
            if(!Cur->Nxt[S[i]]) break;
            
            Cur=Cur->Nxt[S[i]];
            if(Cur->bIsEnd) 
            {
                string Remain=S.substr(i+1,S.size());
                if(Nick.find(Remain)!=Nick.end()) return true;
            }
        }
        return false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>C>>N;
    Trie Color;
    string T;
    
    while(C--)
    {
        cin>>T;
        Color.Insert(T);
    }
    
    while(N--)
    {
        cin>>T;
        Nick.insert(T);
    }
    cin>>Q;
    
    while(Q--)
    {
        string Team;
        cin>>Team;
        int L=Team.size();
       
        bool bIsLegend=Color.CheckWord(Team);
        cout<<(bIsLegend ? "Yes\n" : "No\n");
    }    
}