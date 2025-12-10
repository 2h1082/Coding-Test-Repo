#include "bits/stdc++.h"
using namespace std;

int N;

bool IsPossible(string Expr)
{
    Expr.erase(remove(Expr.begin(),Expr.end(),' '),Expr.end());
    
    int Sum=0, Cur=Expr[0]-'0';
    char Op='+';
    
    for(int i=1;i<Expr.size();++i)
    {
        if(isdigit(Expr[i])) Cur=Cur*10+(Expr[i]-'0');
        else
        {
            if(Op=='+') Sum+=Cur;
            else        Sum-=Cur;
            
            Op=Expr[i];
            Cur=0;
        }
    }
    if(Op=='+') Sum+=Cur;
    else        Sum-=Cur;
    
    return Sum==0;
}
void DFS(int Cur, string Expr)
{
    if(Cur==N)
    {
        if(IsPossible(Expr))
        {
            cout<<Expr<<'\n';
        }
        return;
    }
    
    int Nxt=Cur+1;
    DFS(Nxt,Expr+' '+char(Nxt+'0'));
    DFS(Nxt,Expr+'+'+char(Nxt+'0'));
    DFS(Nxt,Expr+'-'+char(Nxt+'0'));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin>>T;
    
    while(T--)
    {
        cin>>N;
        
        DFS(1,"1");
        cout<<'\n';
    }
}