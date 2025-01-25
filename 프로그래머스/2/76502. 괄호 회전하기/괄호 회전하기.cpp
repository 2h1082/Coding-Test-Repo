#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int sIdx=s.size()-1;
    vector<char> IsOpen;
    bool pushed=false;
    for(int i=0;i<sIdx;++i)
    {
        for(int j=i;j<i+s.size();++j)
        {
            if( s[j%(sIdx+1)]=='[')
            {
                IsOpen.push_back(']');
                pushed=true;
            }
            else if( s[j%(sIdx+1)]=='{')
            {
                IsOpen.push_back('}');
                pushed=true;
            }
            else if( s[j%(sIdx+1)]=='(')
            {
                IsOpen.push_back(')');
                pushed=true;
            }
            else if(!IsOpen.empty())
            {
                if( s[j%(sIdx+1)]==IsOpen.back())
                {
                    IsOpen.pop_back();
                }
                else if( s[j%(sIdx+1)]==IsOpen.back())
                {
                    IsOpen.pop_back();
                }
                else if( s[j%(sIdx+1)]==IsOpen.back())
                {
                    IsOpen.pop_back();
                }
            }
        }
        if(IsOpen.empty() && pushed==true)
        {
            ++answer;      
        }
        IsOpen.clear();
    }
    return answer;
}
               