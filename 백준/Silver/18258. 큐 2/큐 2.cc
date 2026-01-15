#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    deque<int> Q;
    int N;
    cin>>N;
    
    while(N--)
    {
        string S;
        cin>>S;
        
        if(S=="push")
        {
            int X;
            cin>>X;
            Q.push_back(X);
        }
        else if(S=="pop")
        {
            if(Q.empty()) cout<<-1<<'\n';
            else     
            {
                cout<<Q.front()<<'\n';
                Q.pop_front();
            }
        }
        else if(S=="size")
        {
            cout<<Q.size()<<'\n';
        }
        else if(S=="empty")
        {
            if(Q.empty()) cout<<1<<'\n';
            else          cout<<0<<'\n';
        }
        else if(S=="front")
        {
            if(Q.empty()) cout<<-1<<'\n';
            else          cout<<Q.front()<<'\n';
        }
        else if(S=="back")
        {
            if(Q.empty()) cout<<-1<<'\n';
            else          cout<<Q.back()<<'\n';
        }
    }
}