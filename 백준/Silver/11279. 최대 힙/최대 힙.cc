#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
int N;
priority_queue<int> Que;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    while(N--){
        int X;
        cin>>X;
        if(X==0){
            if(Que.empty()) 
                cout<<"0\n";
            else{
                cout<<Que.top()<<"\n";
                Que.pop();
            }
        }
        else
            Que.push(X);
    }
}