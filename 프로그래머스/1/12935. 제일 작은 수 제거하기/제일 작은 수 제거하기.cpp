#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min=0;
    if(arr.size()==1){
        answer.push_back(-1);
        return answer;
    }
    for(int i=0;i<arr.size();i++){
        if(arr[i]<arr[min])
            min=i;
    }
    arr.erase(arr.begin()+min);
    answer=arr;
    return answer;
}