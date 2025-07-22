#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int A=0, B=0;
    cin>>A>>B;
    vector<int> Out;
    Out.push_back(A+B);
    Out.push_back(A-B);
    Out.push_back(A*B);
    Out.push_back(A/B);
    Out.push_back(A%B);
    
    for(int i=0;i<Out.size();++i)
    {
        cout<<Out[i]<<'\n';    
    }
    
}