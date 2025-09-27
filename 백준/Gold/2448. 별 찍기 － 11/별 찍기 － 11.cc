#include <iostream>
#include <vector>

using namespace std;
int Len=0;
vector<string> Stars;
void PrintStar(int N, int Row, int Col)
{
    if(N==3)
    {
        Stars[Row][Col]='*';
        Stars[Row+1][Col-1]='*';
        Stars[Row+1][Col+1]='*';
        Stars[Row+2][Col-2]='*';
        Stars[Row+2][Col-1]='*';
        Stars[Row+2][Col]='*';
        Stars[Row+2][Col+1]='*';
        Stars[Row+2][Col+2]='*';
        return;
    }
    PrintStar(N/2,Row,Col);
    PrintStar(N/2,Row+N/2,Col-(N/2));
    PrintStar(N/2,Row+N/2,Col+(N/2));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N=0;
    cin>>N;
    Len=2*N-1;
    Stars.assign(N,string(Len,' '));
    PrintStar(N,0,Len/2);
    for(auto& S : Stars)
    {
        for(auto& C : S)
        {
            cout<<C;
        }
        cout<<"\n";
    }
}