#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    char Game;
    map<char,int> P={{'Y',2},{'F',3},{'O',4}};
    cin>>N>>Game;
    
    set<string> Previous;
    int Cnt=1, Res=0;
    while(N--)
    {
        string Name;
        cin>>Name;
        if(Previous.find(Name)==Previous.end())
        {
            Previous.insert(Name);
            Cnt++;
            if(Cnt==P[Game])
            {
                Res++;
                Cnt=1;
            }
        }
    }
    cout<<Res;
}