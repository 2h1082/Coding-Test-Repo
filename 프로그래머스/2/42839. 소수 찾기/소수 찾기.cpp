#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool IsPrime(long long num)
{
    if(num<2) return false;
    if(num==2 || num==3) return true;
    if(num%2==0 || num%3==0) return false;
    
    for(long long i=5;i*i<=num;i+=6)
    {
        if(num%i==0||num%(i+2)==0) return false;
    }
    return true;
}
int solution(string numbers) {
    int answer = 0;
    unordered_set<long long> visited;
    sort(numbers.begin(),numbers.end());
    do
    {
        string temp="";
        for(char s : numbers)
        {
            if(IsPrime(s-'0')) visited.insert(s-'0');
            temp+=s;
            if(IsPrime(stoll(temp))) visited.insert(stoll(temp));
        }
    } while(next_permutation(numbers.begin(),numbers.end()));
    return visited.size();
}