#include <iostream>
#include <deque>
#include <sstream>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=0;
    cin>>T;
    while(T--)
    {
        string Command,P;
        int N=0;
        deque<int> dq;
        cin>>Command>>N>>P;
        P=P.substr(1,P.length()-2);
        stringstream ss(P);
        string Temp;
        while(getline(ss,Temp,','))
        {
            if(!Temp.empty())
            {
                dq.push_back(stoi(Temp));
            }
        }
        bool bIsReverse=false;
        bool bIsError=false;
        for(auto& C : Command)
        {
            if(C=='R')
            {
                bIsReverse=!bIsReverse;
            }
            else if(C=='D')
            {
                if(dq.empty())
                {
                    bIsError=true;
                    break;
                } 
                else if(bIsReverse)
                {
                    dq.pop_back();
                }
                else
                {
                    dq.pop_front();
                }
            }
        }
        if(bIsError)
        {
            cout<<"error\n";
            continue;
        }
        cout<<"[";
        
        if(!dq.empty())
        {
            if(bIsReverse)
            {
                cout<<dq.back();
                for(auto it=dq.rbegin()+1;it!=dq.rend();++it)
                {
                    cout<<","<<*it;
                }
            }
            else
            {
                cout<<dq.front();
                for(auto it=dq.begin()+1;it!=dq.end();++it)
                {
                    cout<<","<<*it;
                }
            }
        }
        cout<<"]\n";
    }
}