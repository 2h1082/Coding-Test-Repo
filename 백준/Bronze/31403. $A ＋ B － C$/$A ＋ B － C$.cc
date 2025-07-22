#include <iostream>

using namespace std;
int main()
{
    string CharA, CharB, CharC;
    cin>>CharA>>CharB>>CharC;
    
    int A=stoi(CharA);
    int B=stoi(CharB);
    int C=stoi(CharC);
    
    int Out1=A+B-C;
    string Temp;
    Temp+=CharA;
    Temp+=CharB;
    int Out2=stoi(Temp)-C;
    cout<<Out1<<"\n"<<Out2;
    
}