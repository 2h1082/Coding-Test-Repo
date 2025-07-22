#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int A, B, C;
    cin>>A>>B>>C;
    
    int result=A*B*C;
    string Nums=to_string(result);
    vector<int> Count(10);
    for(auto& c:Nums)
    {
        Count[c-'0']++;
    }
    for(int& N : Count)
    {
        cout<<N<<"\n";
    }
}