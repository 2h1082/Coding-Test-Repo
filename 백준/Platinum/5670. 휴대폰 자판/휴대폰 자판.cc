#include <bits/stdc++.h>

using namespace std;

struct Trie
{
    bool bIsEnd;
    int ChildCnt;
    Trie* Nxt[26];
    Trie()
    {
        bIsEnd=false;
        ChildCnt=0;
        fill(Nxt,Nxt+26,nullptr);
    }
    void Insert(const string& S, int Idx=0)
    {
        if(Idx==S.size())
        {
            bIsEnd=true;
            return;
        }
        int c=S[Idx]-'a';
        if(!Nxt[c])
        {
            Nxt[c]=new Trie();
            ChildCnt++;
        }
        Nxt[c]->Insert(S,Idx+1);
    }
    ~Trie()
    {
        for(int i=0;i<26;++i)
        {
            delete Nxt[i];
        }
    }
};
int Count(const string& S, Trie* Root)
{
    int Cnt=0;
    Trie* Cur=Root;
    for(int i=0;i<S.size();++i)
    {
        if(!i || Cur->ChildCnt>1 || Cur->bIsEnd) Cnt++;
        Cur=Cur->Nxt[S[i]-'a'];
    }
    return Cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N=0;
    while(cin>>N)
    {
        vector<string> Words(N);
        Trie* Root=new Trie();
        for(auto& w : Words) 
        {
            cin>>w;
            Root->Insert(w);
        }
        long long Total=0;
        for(auto& w : Words)
        {
            Total+=Count(w,Root);
        }
        cout<<fixed<<setprecision(2)<<(double)Total/N<<"\n";
        delete Root;
    }
}