using namespace std;

int GCD(int a, int b)
{
    while(b)
    {
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

long long solution(int w,int h) {
    long long answer = (long long)w*h-(w+h-GCD(w,h));
    
    return answer;
}