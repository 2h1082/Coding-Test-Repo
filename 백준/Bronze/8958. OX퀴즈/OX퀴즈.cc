#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int T=0;
    cin>>T;
    for(int i=0;i<T;++i)
    {
        string Result;
        cin>>Result;
        int Score=1;
        int Sum=0;
        for(int j=0;j<Result.size();++j)
        {
            if(Result[j] == 'O') 
            {
                Sum+=Score++;
            }
            else
            {
                Score=1;
            }
        }
        cout<<Sum<<"\n";
    }
}