#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_w=0, max_h=0;
    for(auto& size : sizes){
        if(size[0]<size[1]){
            swap(size[0],size[1]);
        }
        max_w=max(max_w,size[0]);
        max_h=max(max_h,size[1]);
    }
    return max_w*max_h;
}