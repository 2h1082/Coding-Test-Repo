#include "bits/stdc++.h"
using namespace std;

bool IsVowel(char c)
{
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}
bool IsPossible(string& In)
{
    bool bHasVowel=false;
    for(char& c : In) 
    {
        if(IsVowel(c))
        {
            bHasVowel=true;
            break;
        }
    }
    if(!bHasVowel) return false;
    for(int i=1;i<In.size();++i)
    {
        if(In[i-1]==In[i] && !(In[i]=='e' || In[i] == 'o'))
        {                
            return false;
        }
    }
    int Cnt=0;
    for(int i=1;i<In.size();++i)
    {
        if(IsVowel(In[i-1])==IsVowel(In[i]))
        {
            Cnt++;
            if(Cnt>=2)
            {                
                return false;
            }
        }
        else
        {
            Cnt=0;
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    while(1)
    {
        string In;
        cin>>In;
        if(In=="end") break;
        
        cout<<'<'<<In<<"> ";
        
        if(IsPossible(In)) cout<<"is acceptable.\n";
        else               cout<<"is not acceptable.\n";
    }
}