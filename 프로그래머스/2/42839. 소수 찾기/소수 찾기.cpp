#include "bits/stdc++.h"
using namespace std;
using ll=long long;

unordered_set<ll> Prime;
vector<bool> Used;
bool IsPrime(ll Num)
{
    if(Num<=1) return false;
    if(Num<=3) return true;
    if(Num%2==0 || Num%3==0) return false;
    
    for(ll i=5;i*i<=Num;i+=6)
    {
        if(!(Num%i) || !(Num%(i+2))) return false;
    }
    return true;
}
void DFS(string Cur, const string& Nums)
{
    if(!Cur.empty())
    {
        ll Num=stoll(Cur);
        if(IsPrime(Num)) Prime.insert(Num);
    }
    
    for(int i=0;i<Nums.size();++i)
    {
        if(Used[i]) continue;
        Used[i]=true;
        DFS(Cur+Nums[i],Nums);
        Used[i]=false;
    }
   
}
int solution(string Nums) 
{
    Used.assign(Nums.size(),false);
    DFS("",Nums);    
    
    return Prime.size();
}