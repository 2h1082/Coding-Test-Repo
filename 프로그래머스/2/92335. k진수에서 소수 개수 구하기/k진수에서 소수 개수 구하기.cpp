#include <string>
#include <vector>

using namespace std;

bool IsPrime(long long n)
{
    if(n<2) return false;
    if(n==2||n==3) return true;
    if(n%2==0 || n%3==0) return false;
    for(long long i=5;i*i<=n;i+=6)
    {
        if(n%i==0||n%(i+2)==0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string KDigit="";
    while(n>0)
    {
        KDigit=to_string(n%k)+KDigit;
        n/=k;
    }
    
    size_t Start=0;
    while(Start<KDigit.size())
    {
        size_t End=KDigit.find('0',Start);
        if(End==string::npos) End=KDigit.size();
        if(Start<End)
        {
            if(IsPrime(stol(KDigit.substr(Start,End-Start)))) ++answer;   
        }
        Start=End+1;
    }
    return answer;
}