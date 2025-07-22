#include <iostream>

using namespace std;
int main()
{
    int H, M;
    cin>>H>>M;
    
    if(M-45<0) 
    {
        H = (H-1<0) ? 23 : H-1;
        M=60-(45-M);
    }
    else
    {
        M-=45;
    }
    cout<<H<<" "<<M;
}