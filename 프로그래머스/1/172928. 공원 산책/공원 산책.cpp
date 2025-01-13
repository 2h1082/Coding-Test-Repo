#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int maxH=park.size()-1;
    int maxW=park[0].size()-1;
    vector<int> current;
    for(int j=0;j<park.size();j++){
        for(int i=0;i<park[0].size();i++){
            if(park[j][i]=='S'){
                current.push_back(j);
                current.push_back(i);
            }
        }
    }
    cout<<current[0]<<" "<<current[1]<<endl;
    for(string command : routes){
        char direction=command[0];
        int distance=command[2]-'0';
        if(direction=='E'){
            if(maxW>=current[1]+distance){
                int impossible=0;
                for(int i=current[1]+1;i<=current[1]+distance;i++){
                    if(park[current[0]][i]=='X'){
                        impossible=1;
                        break;
                    }
                }
                if(impossible==0){
                    current[1]+=command[2]-'0';
                }
            }
        }
        else if(direction=='W'){
            if(0<=current[1]-distance){
                int impossible=0;
                for(int i=current[1]-1;i>=current[1]-distance;i--){
                    if(park[current[0]][i]=='X'){
                        impossible=1;
                        break;
                    }
                }
                if(impossible==0){
                    current[1]-=command[2]-'0';
                }
            }
        }
        else if(direction=='N'){
            if(0<=current[0]-distance){
                int impossible=0;
                for(int i=current[0]-1;i>=current[0]-distance;i--){
                    if(park[i][current[1]]=='X'){
                        impossible=1;
                        break;
                    }
                }
                if(impossible==0){
                    current[0]-=command[2]-'0';   
                }
            }
        }
        else if(direction=='S'){
            if(maxH>=current[0]+distance){
                int impossible=0;
                for(int i=current[0]+1;i<=current[0]+distance;i++){
                    if(park[i][current[1]]=='X'){
                        impossible=1;
                        break;
                    }
                }
                if(impossible==0){
                    current[0]+=command[2]-'0';   
                }
            }
        }
        cout<<current[0]<<" "<<current[1]<<endl;
    }
    answer.push_back(current[0]);
    answer.push_back(current[1]);
    return answer;
}