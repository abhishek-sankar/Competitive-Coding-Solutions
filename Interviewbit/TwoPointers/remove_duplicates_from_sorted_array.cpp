/*
https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/
Remove Duplicates from Sorted Array
Asked in:  United Healthgroup, Amazon, Google, Microsoft, Expedia

Remove duplicates from Sorted Array
Given a sorted array, remove the duplicates in place such that each element appears only once and return the new length.
Note that even though we want you to return the new length, make sure to change the original array as well in place
Do not allocate extra space for another array, you must do this in place with constant memory.

 Example:
Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2]. 
*/

int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    for(int i=A.size()-1;i>0;i--){
        if(A[i]==A[i-1]){
            A.erase(A.begin()+i);
        }
    }
    return A.size();
}
