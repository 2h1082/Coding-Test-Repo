#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    string temp;
    vector<int> number;
    while(ss>>temp){
        number.push_back(stoi(temp));
    }
    sort(number.begin(),number.end());
    answer+=to_string(number[0])+" ";
    answer+=to_string(number[number.size()-1]);
    return answer;
}