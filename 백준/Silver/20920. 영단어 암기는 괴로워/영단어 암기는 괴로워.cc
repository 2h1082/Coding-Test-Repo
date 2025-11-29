#include "bits/stdc++.h"
using namespace std;
    
struct Words
{
    int Cnt, Len;
    string s;
    Words(string S, int C, int L)
    {
        s=S;
        Cnt=C;
        Len=L;
    }
    bool operator <(const Words& other) const
    {
        if(Cnt!=other.Cnt) return Cnt>other.Cnt;
        if(Len!=other.Len) return Len>other.Len;
        return s<other.s;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M;
    cin>>N>>M;
    map<string,int> Idx;
    vector<Words> Book;
    while(N--)
    {
        string T;
        cin>>T;
        int L=T.length();
        if(Idx.find(T)!=Idx.end())
        {
            Book[Idx[T]].Cnt++;
        }
        else if(L>=M)
        {
            Idx[T]=Book.size();
            Words Cur(T,1,L);
            Book.push_back(Cur);
        }
    }
    sort(Book.begin(),Book.end());
    for(auto& b : Book) cout<<b.s<<'\n';
}