#include <bits/stdc++.h>

using namespace std;

int Convert(string time)
{
    int minute=stoi(time.substr(0,2))*60+stoi(time.substr(3,2));
    return minute;
}
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<pair<string,int>> st;
    sort(plans.begin(),plans.end(),[](vector<string> a, vector<string> b){
        return Convert(a[1])<Convert(b[1]);
    });
    int time=Convert(plans[0][1]);
    for(int i=1;i<plans.size();i++)
    {
        time+=stoi(plans[i-1][2]);
        if(time>Convert(plans[i][1]))
        {
            int dif=time-Convert(plans[i][1]);
            time-=dif;
            st.push({plans[i-1][0],dif});
        }
        else
        {
            answer.push_back(plans[i-1][0]);
            int dif=Convert(plans[i][1])-time;
            while(!st.empty()&&dif>0)
            {
                if(st.top().second<=dif)
                {
                    answer.push_back(st.top().first);
                    dif-=st.top().second;
                    st.pop();
                }
                else
                {
                    st.top().second-=dif;
                    dif=0;
                }
            }
            time=Convert(plans[i][1]);
        }
    }
    answer.push_back(plans.back()[0]);
    while(!st.empty())
    {
        answer.push_back(st.top().first);
        st.pop();
    }
    return answer;
}