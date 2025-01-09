#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int lux=50, luy=50, rdx=0, rdy=0;
    for(int y=0;y<wallpaper.size();y++){
        for(int x=0;x<wallpaper[y].size();x++){
            if(wallpaper[y][x]=='#'){
                if(luy>y) luy=y;
                if(lux>x) lux=x;
                if(rdx<x+1) rdx=x+1;
                if(rdy<y+1) rdy=y+1;
            }
        }
    }
    answer.push_back(luy);
    answer.push_back(lux);
    answer.push_back(rdy);
    answer.push_back(rdx);
    return answer;
}