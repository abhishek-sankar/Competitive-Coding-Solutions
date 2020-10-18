/*
https://www.interviewbit.com/problems/search-for-a-range/
If you're smart, you'd just use upper_bound and lower_bound, but right now, I dont wanna cheat.

Search for a Range
Asked in:  Google, Microsoft

Given a sorted array of integers A(0 based index) of size N, find the starting and ending position of a given integar B in array A.
Your algorithm’s runtime complexity must be in the order of O(log n).
Return an array of size 2, such that first element = starting position of B in A and second element = ending position of B in A, if B is not found in A return [-1, -1].

Input Format
The first argument given is the integer array A.
The second argument given is the integer B.

Output Format
Return an array of size 2, such that first element = starting position of B in A and second element = ending position of B in A, if B is not found in A return [-1, -1].

Constraints
1 <= N <= 10^6
1 <= A[i], B <= 10^9

For Example
Input 1:
    A = [5, 7, 7, 8, 8, 10]
    B = 8
Output 1:
    [3, 4]
Explanation 1:
    First occurence of 8 in A is at index 3
    Second occurence of 8 in A is at index 4
    ans = [3, 4]

Input 2:
    A = [5, 17, 100, 111]
    B = 3
Output 2:
    [-1, -1]
*/
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int left = 0, right = A.size()-1, mid;
    vector<int>res;
    if(A.size()<1){
        res.push_back(-1);
        res.push_back(-1);
        return res;        
    }else if(A.size()==1){
        if(A[0]==B){
        res.push_back(0);
        res.push_back(0); 
        return res;
        }
    }
    if(A[0]==B){
        res.push_back(0);
    }else{
        while(left<=right){
            mid = left + (right-left)/2;
            // cout<<left<<" "<<right<<" "<<mid<<" "<<A[mid]<<endl;
            if(A[mid]<B && A[mid+1]==B){
                    res.push_back(mid+1);
                    break;
                }
            else if(A[mid+1]<B){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
    }
    if(res.size()==0){
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
    // left = 0;
    left = res[0];
    right = A.size()-1;
    // cout<<"Test"<<endl;
    while(left<=right){
        mid = left + (right-left)/2;
        // cout<<left<<" "<<right<<" "<<mid<<" "<<A[mid]<<endl;
        if(A[mid]==B && mid==A.size()-1){
            res.push_back(mid);
            break;
        }else if(A[mid]==B && A[mid+1]>B){
            res.push_back(mid);
            break;
        }else if(A[mid+1]==B){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    // if(A[A.size()-1]==B)res.push_back(A.size()-1);
    //check if end
    return res;
}
