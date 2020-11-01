/*
https://www.interviewbit.com/problems/intersection-of-sorted-arrays/
Intersection Of Sorted Arrays
Asked in:  Facebook, Google
Find the intersection of two sorted arrays.
OR in other words,
Given 2 sorted arrays, find all the elements which occur in both the arrays.

Example :
Input : 
    A : [1 2 3 3 4 5 6]
    B : [3 3 5]

Output : [3 3 5]
Input : 
    A : [1 2 3 3 4 5 6]
    B : [3 5]
Output : [3 5]
 NOTE : For the purpose of this problem ( as also conveyed by the sample case ), assume that elements that appear more than once in both arrays should be included multiple times in the final output. 
*/

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    vector<int>res;
    for(int i=0, j=0;i<A.size() && j<B.size();){
        if(A[i]==B[j]){
            res.push_back(A[i]);
            i++;
            j++;
        }else if(A[i]<B[j]){
            i++;
        }else{
            j++;
        }
    }
    return res;
}
