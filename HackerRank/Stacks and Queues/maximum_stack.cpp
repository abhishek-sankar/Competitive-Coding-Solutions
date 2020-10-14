#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  

    int no_of_queries,query_type,input, present_max;
    cin>>no_of_queries; 
    stack<int> my_stack;
    while(no_of_queries--){
        cin>>query_type;
        if(query_type==1){
            cin>>input;
            if(my_stack.empty())
            my_stack.push(input);
            else{
                my_stack.push(max(my_stack.top(), input));
            }
        }else if(query_type == 2){
            my_stack.pop();
        }else{
            cout<<my_stack.top();
        }
    }
    return 0;
}
