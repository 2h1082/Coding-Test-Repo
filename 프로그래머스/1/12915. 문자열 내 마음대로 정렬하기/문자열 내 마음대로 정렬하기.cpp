#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    auto compareIndex=[n](const string& a, const string& b){
        if(a.size()>n && b.size()>n){
            if(a[n]==b[n]){
                return a<b;
            }
            return a[n]<b[n];
        }
        return a.size()<b.size();
    };
    sort(strings.begin(),strings.end(),compareIndex);
    vector<string> answer=strings;
    return answer;
}