#include "bits/stdc++.h"
using namespace std;

string solution(vector<int> Numbers) {
    string Ans = "";
    int N=Numbers.size();
    vector<string> Nums(N);
    for(int i=0;i<N;++i) Nums[i]=to_string(Numbers[i]);
    
    sort(Nums.begin(),Nums.end(),[](const string& A, const string& B){
        return A+B > B+A; // 앞에 붙었을 때, 수가 더 커지는 값이 앞에 있도록 정렬
    });
    if(Nums[0]=="0") return "0";
    for(auto& n : Nums) Ans+=n;
    
    return Ans;
}