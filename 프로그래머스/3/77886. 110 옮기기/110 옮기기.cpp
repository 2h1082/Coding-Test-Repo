#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    
    for(auto& str:s)
    {
        stack<char> st;
        int cnt=0;
        for(auto&c :str)
        {
            st.push(c);
            if(st.size()>=3)
            {
                int c1=st.top(); st.pop();
                int c2=st.top(); st.pop();
                int c3=st.top(); st.pop();
                if(c1=='0'&&c2=='1'&&c3=='1')
                {
                    cnt++;
                }
                else
                {
                    st.push(c3);
                    st.push(c2);
                    st.push(c1);
                }
            }
        }
        string remain;
        while(!st.empty())
        {
            remain.push_back(st.top());
            st.pop();
        }
        reverse(remain.begin(),remain.end());
        string merged;
        int pos=remain.find_last_of('0');
        if (pos == string::npos) 
        {
            for (int i = 0; i < cnt; i++) 
            {
                merged += "110";
            }
            merged += remain;
        } 
        else 
        {
            merged += remain.substr(0, pos + 1);
            for (int i = 0; i < cnt; i++) 
            {
                merged += "110";
            }
            merged += remain.substr(pos + 1);
        }
        
        answer.push_back(move(merged));
    }
    return answer;
}
