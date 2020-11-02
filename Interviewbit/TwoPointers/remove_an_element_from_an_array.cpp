/*
https://www.interviewbit.com/problems/remove-element-from-array/
Remove Element from Array
Asked in:  Amazon
Remove Element

Given an array and a value, remove all the instances of that value in the array.
Also return the number of elements left in the array after the operation.
It does not matter what is left beyond the expected length.

Example:
If array A is [4, 1, 1, 2, 1, 3]
and value elem is 1,
then new length is 3, and A is now [4, 2, 3] 
Try to do it in less than linear additional space complexity.
*/

int Solution::removeElement(vector<int> &A, int B) {
    int i=0, j=0, flag=0, count=0;
    for(i=0;j<A.size();){
        if(A[j]==B){
            j++;
            count++;
            continue;
        }
        A[i] = A[j];
        // i++;
        i++;
        j++;
    }
    return A.size()-count;
}
