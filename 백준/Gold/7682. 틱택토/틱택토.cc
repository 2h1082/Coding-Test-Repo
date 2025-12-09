#include "bits/stdc++.h"
using namespace std;

string S;
bool IsEnd(char C)
{
    if((S[0]==C && S[1]==C && S[2]==C)
      || (S[3]==C && S[4]==C && S[5]==C)
      || (S[6]==C && S[7]==C && S[8]==C)
      || (S[0]==C && S[4]==C && S[8]==C)
      || (S[2]==C && S[4]==C && S[6]==C)
      || (S[0]==C && S[3]==C && S[6]==C)
      || (S[1]==C && S[4]==C && S[7]==C)
      || (S[2]==C && S[5]==C && S[8]==C)) 
             return true;
    else     return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(1)
    {
        cin>>S;
        if(S=="end") break;
        
        int XCnt=0, OCnt=0;
        for(char& c : S)
        {
            if(c=='X')      XCnt++;
            else if(c=='O') OCnt++;
        }
        
        int Diff=XCnt-OCnt;
        bool bEndByX=IsEnd('X'), bEndByO=IsEnd('O');
        if((Diff < 0) ||
          (bEndByX && bEndByO) ||
          (bEndByO && (Diff != 0)) ||
          (bEndByX && (Diff != 1)) ||
          (!bEndByX && !bEndByO && (XCnt+OCnt != 9)))  
        {
            cout<<"invalid\n";
            continue;
        }
        cout<<"valid\n";
    }
}