#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int C, N, Q;
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
    int CheckWord(const string& S, vector<bool>& Check)
    {
        Trie* Cur=this;
        for(int i=0;i<S.size();++i)
        {
            if(!Cur->Nxt[S[i]]) break;
            
            Cur=Cur->Nxt[S[i]];
            if(Cur->bIsEnd) Check[i]=true;
        }
        return 0;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>C>>N;
    Trie Color, Nick;
    string T;
    
    while(C--)
    {
        cin>>T;
        Color.Insert(T);
    }
    
    while(N--)
    {
        cin>>T;
        reverse(T.begin(),T.end());
        Nick.Insert(T);
    }
    cin>>Q;
    
    while(Q--)
    {
        string Team;
        cin>>Team;
        int L=Team.size();
        
        vector<bool> ColEnd(L,false), NickEnd(L,false);
        Color.CheckWord(Team,ColEnd);
        reverse(Team.begin(),Team.end());
        Nick.CheckWord(Team,NickEnd);
        reverse(NickEnd.begin(),NickEnd.end());
        
        bool bIsLegendary=false;
        for(int i=0;i<L-1;++i)
        {
            if(ColEnd[i]&&NickEnd[i+1])
            {
                bIsLegendary=true;
                break;
            }
        }
        cout<<(bIsLegendary ? "Yes\n" : "No\n");
    }    
}