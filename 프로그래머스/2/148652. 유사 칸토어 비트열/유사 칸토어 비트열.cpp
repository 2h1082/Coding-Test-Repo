#include <bits/stdc++.h>

using namespace std;
int countOnes(int n, long long l, long long r, long long start=1, long long size=-1)
{
    if(size==-1) size=pow(5,n);
    if(r<start||l>start+size-1) return 0;
    if(n==0) return 1;
    long long subsize=size/5;
    int count=0;
    for(int i=0;i<5;i++)
    {
        long long substart=start+i*subsize;
        if(i==2) continue;
        count+=countOnes(n-1,l,r,substart,subsize);
    }
    return count;
}
int solution(int n, long long l, long long r) 
{   
    return countOnes(n,l,r);
}