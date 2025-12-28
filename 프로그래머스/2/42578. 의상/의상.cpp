#include "bits/stdc++.h"
using namespace std;

int solution(vector<vector<string>> Cloth) 
{
    map<string,int> Cnt;
    for(auto& C : Cloth)
    {
        string Type=C[1];
        Cnt[Type]++;
    }
    int Ans=1;
    for(auto& [Name, Count] : Cnt)
    {
        Ans*=Count+1;
    }
    Ans--;
    return Ans;
}