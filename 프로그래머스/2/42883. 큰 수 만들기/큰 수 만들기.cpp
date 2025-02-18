#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> s;
    int toRemove = k;  

    for (char digit : number) {
        while (!s.empty() && toRemove > 0 && s.top() < digit) {
            s.pop();
            toRemove--;
        }
        s.push(digit);
    }
    while (toRemove > 0) {
        s.pop();
        toRemove--;
    }

    while (!s.empty()) {
        answer = s.top()+answer;
        s.pop();
    }
    return answer;
}
