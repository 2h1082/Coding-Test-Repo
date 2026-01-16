#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin>>T;
    
    while(T--)
    {
        string P, S;
        int N;
        cin>>P>>N>>S;
        
        deque<int> Q;
        string Temp;
        S=S.substr(1,S.length()-2);
        stringstream ss(S);
        while(getline(ss,Temp,','))
        {
            if(!Temp.empty()) Q.push_back(stoi(Temp));
        }
        
        bool bIsReverse=false, bIsError=false;
        for(auto& c : P)
        {
            if(c=='R')
            {
                bIsReverse=!bIsReverse;
            }
            else if(c=='D') 
            {
                if(Q.empty())
                {
                    bIsError=true;
                    break;
                }
                if(bIsReverse) Q.pop_back();
                else           Q.pop_front();
            }
        }
        if(bIsError)
        {
            cout<<"error\n";
            continue;
        }
        cout<<'[';
        if(!Q.empty())
        {
            if(bIsReverse)
            {
                cout<<Q.back();
                for(auto It=Q.rbegin()+1;It!=Q.rend();++It)
                {
                    cout<<','<<*It;
                }
            }
            else
            {
                cout<<Q.front();
                for(auto It=Q.begin()+1;It!=Q.end();++It)
                {
                    cout<<','<<*It;
                }
            }
        }
        cout<<"]\n";
    }
}