#include <string>
#include <vector>
#include <map>

using namespace std;

int CalculateMinute(string InTime, string OutTime)
{
    int OutHour=stoi(OutTime.substr(0,2));
    int OutMin=stoi(OutTime.substr(3,2));
    int InHour=stoi(InTime.substr(0,2));
    int InMin=stoi(InTime.substr(3,2));
    
    int InTotalMin=InHour*60+InMin;
    int OutTotalMin=OutHour*60+OutMin;
    return OutTotalMin-InTotalMin;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, string> InTime;
    map<string, int> TotalParkingMinute;
    for(const string& r : records)
    {
        if(r.substr(11,2)=="IN")
        {
            InTime[r.substr(6,4)]=r.substr(0,5);
        }
        else
        {
            TotalParkingMinute[r.substr(6,4)]+=CalculateMinute(InTime[r.substr(6,4)],r.substr(0,5));
            InTime.erase(r.substr(6,4));
        }
    }
    
    for(auto it=InTime.begin();it!=InTime.end();++it)
    {
        TotalParkingMinute[it->first]+=CalculateMinute(it->second,"23:59");
    }
    
    for(auto it=TotalParkingMinute.begin();it!=TotalParkingMinute.end();++it)
    {
        if(it->second>fees[0])
        {
            int Ceil=(it->second-fees[0])%fees[2]!=0 ? 1 : 0;
            int fee=fees[1]+((it->second-fees[0])/fees[2]+Ceil)*fees[3];
            answer.push_back(fee);
        }
        else
        {
            answer.push_back(fees[1]);
        }
    }
    return answer;
}