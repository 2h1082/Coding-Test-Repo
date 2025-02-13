#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> s;
    for(int i:numbers)
    {
        s.push_back(to_string(i));
    }
    sort(s.begin(),s.end(),[](string a, string b){
       return a+b>b+a; 
    });
    if(s[0]=="0") return "0";
    for(string s1:s)
    {
        answer+=s1;
    }
    return answer;
}