#include <bits/stdc++.h>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    
    long long MaxPlus=0, MaxMinus=0;
    long long PlusSub=0, MinusSub=0;
    int PlusS=1, MinusS=-1;
    for(int i=0;i<sequence.size();i++)
    {
        
        PlusSub=max(((long long)PlusS*sequence[i])+PlusSub,(long long)sequence[i]*PlusS);
        MinusSub=max(((long long)MinusS*sequence[i])+MinusSub,(long long)sequence[i]*MinusS);
        
        MaxPlus=max(MaxPlus,PlusSub);
        MaxMinus=max(MaxMinus,MinusSub);
        PlusS=-PlusS;
        MinusS=-MinusS;
    }
    
    answer=max(MaxPlus,MaxMinus);
    return answer;
}