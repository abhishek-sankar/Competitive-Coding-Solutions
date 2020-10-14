#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include "stack"
using namespace std;
struct Queue{
    stack<int> s1, s2;
    int front = -1;
    void enQueue(int data){
        s1.push(data);
    }
    void deQueue(){
        if(s1.empty() && s2.empty()){
            front = -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
        if(!s2.empty())
        front = s2.top();
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int q, qType, value;
    Queue q1;
    cin>>q;
    while(q--){
        cin>>qType;
        if(qType==1){
            cin>>value;
            q1.enQueue(value);
        }else if(qType==2){
            q1.deQueue();
        }else{
            cout<<q1.front<<" ";
        }
    } 
    return 0;
}
