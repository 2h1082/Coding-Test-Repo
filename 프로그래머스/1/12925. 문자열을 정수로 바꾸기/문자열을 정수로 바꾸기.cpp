#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int len=s.length()-1;
    int minus=0;
    int idx=1;
    for(int i=0;i<s.length();i++){
        if(s[i]=='-'){
            minus=1;
        }else if(s[i]=='+'){}
        else{
            if(!(len-i)){
                answer+=(s[i]-'0');
            }
            else{
                for(int j=0;j<(len-i);j++){
                    idx*=10;
                }
                answer+=idx*(s[i]-'0');
                cout<<answer<<" ";
                idx=1;
            }
        }
    }
    return minus?-(answer):answer;
}