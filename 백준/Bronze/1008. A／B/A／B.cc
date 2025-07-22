#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    int a=0, b=0;
    
    cin>>a>>b;
    double result= 0;
    result=static_cast<double>(a)/b;
    cout << fixed << setprecision(9) << result << endl;
}