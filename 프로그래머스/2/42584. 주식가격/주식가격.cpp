#include "bits/stdc++.h"

using namespace std;

vector<int> solution(vector<int> prices) {
    int N=prices.size();
    vector<int> answer(N,0);
    stack<int> st;
    
    for(int i=0;i<N;++i)
    {
        while(!st.empty() && (prices[st.top()] > prices[i]))
        {
            int Prev=st.top();
            st.pop();
            answer[Prev]=i-Prev;
        }
        st.push(i);
    }
    while(!st.empty())
    {
        int Prev=st.top();
        st.pop();
        answer[Prev]=N-Prev-1;
    }
    return answer;
}