#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> v;
    while(n){
        v.push_back(n%10);
        n/=10;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        answer+=(pow(10,i)*v[i]);
    }
    return answer;
}