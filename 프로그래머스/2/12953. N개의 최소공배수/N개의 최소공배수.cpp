#include <string>
#include <vector>

using namespace std;

int GetGCD(int a, int b){
    int r;
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int GetLCM(int a, int b){
    return (a*b)/GetGCD(a,b);
}

int solution(vector<int> arr) {
    int prevLCM=arr.at(0);
    for(int i=1;i<arr.size();i++){
        int temp=GetLCM(prevLCM,arr.at(i));
        prevLCM=temp;
    }
    return prevLCM;
}