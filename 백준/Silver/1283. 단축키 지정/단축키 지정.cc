#include <sstream>

#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    cin.ignore();
    
    vector<string> W(N);
    vector<bool> Visited(26,false);
    for(auto& s : W) 
    {
        getline(cin,s);
    }
    
    for (auto& s : W)
    {
        int Pos=-1;
        bool bIsFirst=true;
        for(int i=0;i<s.size();++i)
        {
            char C=toupper(s[i]);
            if(bIsFirst)
            {
                if (C >= 'A' && C <= 'Z' && !Visited[C-'A'])
                {
                    Visited[C-'A'] = true;
                    Pos=i;
                    break;
                }
            }
            if(s[i] == ' ') bIsFirst=true;
            else            bIsFirst=false;
        }
        
        if (Pos==-1)
        {
            for (int i=0;i<s.size();++i)
            {
                char C= toupper(s[i]);
                if (C >= 'A' && C <= 'Z' && !Visited[C-'A'])
                {
                    Visited[C-'A'] = true;
                    Pos=i;
                    break;
                }
            }
        }
        if (Pos != -1)
        {
            cout<<s.substr(0,Pos)<<'['<<s[Pos]<<']'<<s.substr(Pos+1)<<'\n';
        }
        else
        {
            cout<<s<<'\n';
        }
    }
}