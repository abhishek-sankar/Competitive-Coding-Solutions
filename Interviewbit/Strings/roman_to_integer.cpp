/*
https://www.interviewbit.com/problems/roman-to-integer/

Roman To Integer
Asked in:  Amazon, Facebook, Microsoft, Twitter, 
Given a string A representing a roman numeral.
Convert A into integer.
A is guaranteed to be within the range from 1 to 3999.

Input Format
The only argument given is string A.
Output Format
Return an integer which is the integer verison of roman numeral string.

For Example
Input 1:
    A = "XIV"
Output 1:
    14
Input 2:
    A = "XX"
Output 2:
    20
*/

int getRes(char c){
    switch(c){
        case 'I':return 1;
        break;
        case 'V':return 5;
        break;
        case 'X':return 10;
        break;
        case 'L':return 50;
        break;
        case 'C':return 100;
        break;
        case 'D':return 500;
        break;
        case 'M':return 1000;
        break;
    }
}
int Solution::romanToInt(string A) {
    int res = 0;
    //MDCCCIV
    for(int i=0;i<A.size();i++){
        int s1 = getRes(A[i]);
        // cout<<s1<<endl;
        if(i+1<A.size()){
            int s2 = getRes(A[i+1]);
            // cout<<"R "<<s2<<endl;
            if(s2>s1){
                res+=s2-s1;
                // cout<<"res2 "<<res<<endl;
                i++;
            }else{
                res+=s1;
                // cout<<"res1 "<<res<<endl;
            }
        }else{
            res+=s1;
            // cout<<"res1 "<<res<<endl;
        }
    }
    return res;
}
