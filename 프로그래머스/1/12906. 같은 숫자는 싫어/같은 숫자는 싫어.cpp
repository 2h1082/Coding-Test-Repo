#include "bits/stdc++.h"

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    answer.push_back(arr[0]);
    for(int& n : arr)
    {
        if(n==answer.back()) continue;
        answer.push_back(n);
    }

    return answer;
}