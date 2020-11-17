/*
https://www.interviewbit.com/problems/simplify-directory-path/
Simplify Directory Path
Asked in:  
Microsoft
Given a string A representing an absolute path for a file (Unix-style).

Return the string A after simplifying the absolute path.

Note:

Absolute path always begin with ’/’ ( root directory ).

Path will not have whitespace characters.



Input Format

The only argument given is string A.
Output Format

Return a string denoting the simplified absolue path for a file (Unix-style).
For Example

Input 1:
    A = "/home/"
Output 1:
    "/home"

Input 2:
    A = "/a/./b/../../c/"
Output 2:
    "/c"
*/

string Solution::simplifyPath(string A) {
    stack<string>s;
    string small_dir = "";
    int i=0;
    while(!isalpha(A[i])){
        i++;
    }
    for(;i<A.size();i++){
        while(i<A.size() && A[i]!='/'){
            small_dir+=A[i];
            i++;
        }
        if(small_dir.size()!=0){
            // cout<<small_dir<<endl;
            if(small_dir==".."){
                if(s.size()!=0){
                    s.pop();
                }
                small_dir = "";
            }else if(small_dir=="."){
                    small_dir = "";
            }else{
                s.push(small_dir);
                small_dir = "";
            }
        if(A[i]=='/')continue;
        }
    }
    string res = "";
    while(!s.empty()){
        res =  s.top()+ "/" +res;
        s.pop();
    }
    if(res.size()==0)return "/";
    res = "/"+res;
    return res.substr(0, res.size()-1);
    // return res;
}
