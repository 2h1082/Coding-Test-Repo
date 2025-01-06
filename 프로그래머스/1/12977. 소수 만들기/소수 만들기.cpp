#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int n){
    if (n<=1) return false;
    if (n<=3) return true;
    if (n%2==0 || n%3==0) return false;
    
    for(int i=5; i*i<=n;i+=6){
        if(n%i==0 || n%(i+2)==0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    
    for(int i=0;i<nums.size()-2;i++){
        for(int j=i+1;j<nums.size()-1;j++){
            for(int k=j+1;k<nums.size();k++){
                if(isPrime(nums[i]+nums[j]+nums[k])==true) answer++;
            }
        }
    }

    return answer;
}