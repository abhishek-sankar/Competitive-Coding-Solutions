/*
https://www.interviewbit.com/problems/largest-number/
Given a list of non negative integers, arrange them such that they form the largest number.

For example:
Given [3, 30, 34, 5, 9], the largest formed number is 9534330.
*/
bool checkBigNumber(int a, int b){
    string A = to_string(a);
    string B = to_string(b);
    int i;
    for(i=0;i<max(A.size(), B.size());i++){
        if(A[i%A.size()]==B[i%B.size()]){
            continue;
        }else if(A[i%A.size()]<B[i%B.size()]){
            return 0;
        }else return 1;
    }
    if(A[i%A.size()]>B[i%B.size()])
    return 1;
    else return 0;
}
string Solution::largestNumber(const vector<int> &A) {
    vector<int>B;
    for(int i=0;i<A.size();i++){
        B.push_back(A[i]);
    }
    sort(B.begin(), B.end(), checkBigNumber);
    string res;
    for(int i=0;i<B.size();i++){
        res+=to_string(B[i]);
    }
    res.erase(0, min(res.find_first_not_of('0'), res.size()-1));
    if(res=="")return "0";
    else
    return res;
}
