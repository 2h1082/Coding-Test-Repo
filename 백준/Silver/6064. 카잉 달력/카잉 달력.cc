#include <iostream>

using namespace std;
int gcd(int a, int b)
{
    while(b!=0)
    {
        int temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}
int lcm(int a, int b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    int T=0;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int M=0, N=0, x=0, y=0;
        cin>>M>>N>>x>>y;
        int MaxYear=lcm(M,N);
        int k=x;
        bool found=false;
        while(k<=MaxYear)
        {
            int ny=(k-1)%N+1;
            if(ny==y)
            {
                cout<<k<<"\n";
                found=true;
                break;
            }
            k+=M;
        }
        if(!found) cout<<-1<<endl;;
    }
}