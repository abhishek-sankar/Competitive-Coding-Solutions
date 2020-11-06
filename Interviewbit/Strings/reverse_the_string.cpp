/*
https://www.interviewbit.com/problems/reverse-the-string/
*/

string Solution::solve(string A) {
    if(A=="")return "";
    vector<string>v;
    string s="";
    int i=0, j=A.size()-1;
    while(A[j]==' ')j--;
    while(A[i]==' ')i++;
    for(;i<=j;i++){
        if(A[i]!=' '){
            s+=A[i];
        }else{
            while(A[i]==' ')i++;
            i--;
            v.push_back(s);
            s="";
        }
    }
    if(s!="")
    v.push_back(s);
    reverse(v.begin(), v.end());
    s="";
    for(int i=0;i<v.size()-1;i++){
        s+=v[i];
        s+=" ";
    }
    s+=v.back();
    return s;
}
