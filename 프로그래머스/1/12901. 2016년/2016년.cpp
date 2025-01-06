#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int month[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    string week[7]={"FRI","SAT","SUN","MON","TUE","WED","THU"};
    int date=0;
    for(int i=0;i<a-1;i++){
        date+=month[i];
    }
    date+=b-1;
    answer+=week[date%7];
    return answer;
}