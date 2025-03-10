#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b)
{
    while(b!=0)
    {
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    if(arrayA.empty()||arrayB.empty()) return 0;
    int answer = 0;
    int GCDa=arrayA[0];
    int GCDb=arrayB[0];
    for(int i=1;i<arrayA.size();i++)
    {
        GCDa=GCD(arrayA[i],GCDa);
        //cout<<GCDa<<endl;
    }
    for(int i=1;i<arrayB.size();i++)
    {
        GCDb=GCD(arrayB[i],GCDb);
        //cout<<GCDb<<endl;
    }
    for(auto A:arrayA)
    {
        if(A%GCDb==0) 
        {
            GCDb=0;
            break;
        }
    }
    for(auto B:arrayB)
    {
        if(B%GCDa==0) 
        {
            GCDa=0;
            break;
        }
    }
    answer=max(GCDa,GCDb);
    
    return answer==1?0:answer;
}