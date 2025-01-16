#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string s) {
    bool newWord=1;
    for(char &c : s){
        if(isspace(c)){
            newWord=1;
        }
        else if(newWord){
            c=toupper(c);
            newWord=0;
        }
        else if(!newWord){
            c=tolower(c);
        }
    }
    return s;
}