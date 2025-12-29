#include "bits/stdc++.h"
using namespace std;

vector<int> solution(vector<int> Arr) 
{
    vector<int> Ans;
    Ans.push_back(Arr[0]);
    for(auto& a : Arr)
    {
        if(Ans.back()==a) continue;
        Ans.push_back(a);
    }
    return Ans;
}