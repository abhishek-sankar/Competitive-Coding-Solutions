/*
https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/
Remove Duplicates from Sorted Array II
Asked in:  Expedia, Microsoft

Remove Duplicates from Sorted Array
Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
Note that even though we want you to return the new length, make sure to change the original array as well in place

For example,
Given input array A = [1,1,1,2],
Your function should return length = 3, and A is now [1,1,2].
*/

int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    map<int, int>m;
    for(int i=A.size()-1;i>=0;i--){
        if(m.find(A[i])==m.end()){
            m.insert({A[i],1});
        }else{
            if(m[A[i]]==1){
                m[A[i]]++;
            }else if(m[A[i]]==2){
                A.erase(A.begin()+i);
            }
        }
    }
    return A.size();
}
