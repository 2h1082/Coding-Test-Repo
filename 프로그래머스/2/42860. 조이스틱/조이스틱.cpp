#include <bits/stdc++.h>

using namespace std;

int solution(string Name) {
    int Ans=0, N=Name.size(), Min=N-1;
    string Cur(Name.size(),'A');
    if(Cur==Name) return 0;
    
    for(int i=0;i<N;++i)
    {
        if(Cur[i]!=Name[i])
        {
            int Up=Name[i]-'A';
            int Down=26-Up;
            Ans+=min(Up,Down);
            
            int Nxt=i+1;
            while(Nxt<N && Name[Nxt]=='A') ++Nxt;
            int L=i, R=N-Nxt;
            Min=min(Min,L+R+min(L,R));
        }
    }
    return Ans+Min;
}