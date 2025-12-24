#include "bits/stdc++.h"

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> st;
    for(auto& c : s)
    {
        if(c==')' && (st.empty() || st.top()==')'))
        {
            answer=false;
            break;
        }
        else if(c==')' && (!st.empty() || st.top()=='('))
        {
            st.pop();
            continue;
        }
        st.push(c);
    }
    if(!st.empty()) answer=false;
    
    return answer;
}