#include "bits/stdc++.h"
using namespace std;

vector<int> solution(vector<int> Answers) 
{
    vector<int> Ans;
    vector<int> P1={1,2,3,4,5}, P2={2,1,2,3,2,4,2,5}, P3={3,3,1,1,2,2,4,4,5,5};
    int Sol1=0, Sol2=0, Sol3=0, N=Answers.size();
    for(int i=0;i<N;++i)
    {
        if(Answers[i]==P1[i%5])  ++Sol1;
        if(Answers[i]==P2[i%8])  ++Sol2;
        if(Answers[i]==P3[i%10]) ++Sol3;
    }
    int Max=max({Sol1,Sol2,Sol3});
    if(Max==Sol1) Ans.push_back(1);
    if(Max==Sol2) Ans.push_back(2);
    if(Max==Sol3) Ans.push_back(3);
    
    return Ans;
}