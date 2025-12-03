#include "bits/stdc++.h"
using namespace std;

struct Room
{
    vector<pair<string,int>> Info;
    
    Room(int Level, string Name)
    {
        Info.push_back({Name,Level});
    }
    
    void Sort()
    {
        sort(Info.begin(),Info.end());
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int P,M;
    cin>>P>>M;
    
    vector<Room> List;
    while(P--)
    {
        int Lv;
        string Name;
        cin>>Lv>>Name;
        
        if(List.empty())
        {
            Room NewRoom(Lv,Name);
            List.push_back(NewRoom);
        }
        else
        {
            bool bIsJoined=false;
            for(auto& r : List)
            {
                if(r.Info.size()<M && abs(r.Info[0].second-Lv)<=10)
                {
                    r.Info.push_back({Name,Lv});
                    bIsJoined=true;
                    break;
                }
            }
            if(!bIsJoined)
            {
                Room NewRoom(Lv,Name);
                List.push_back(NewRoom);
            }
        }
    }
    for(auto& l : List)
    {
        l.Sort();
        if(l.Info.size()<M)
        {
            cout<<"Waiting!\n";
        }
        else if(l.Info.size()==M)
        {
            cout<<"Started!\n";
        }
        
        for(auto& p : l.Info)
        {
            cout<<p.second<<' '<<p.first<<'\n';
        }
    }
}