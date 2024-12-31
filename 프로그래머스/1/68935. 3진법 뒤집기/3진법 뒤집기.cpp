#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> toRevTernary(int n){
    vector<int> ternary;
    while(n>0){
        int remainder=n%3;
        ternary.push_back(remainder);
        n/=3;
    }
    return ternary;
}
int solution(int n) {
    vector<int> res=toRevTernary(n);
    int idx=1;
    int answer=0;
    for(int i=1;i<=res.size();i++){
        answer+=res[res.size()-i]*idx;
        idx*=3;
    }
    return answer;
}