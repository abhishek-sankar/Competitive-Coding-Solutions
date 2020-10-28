/*
https://www.interviewbit.com/problems/kth-smallest-element-in-the-array/
Kth Smallest Element in the Array
Find the kth smallest element in an unsorted array of non-negative integers.

Definition of kth smallest element
 kth smallest element is the minimum possible n such that there are at least k elements in the array <= n.
In other words, if the array A was sorted, then A[k - 1] ( k is 1 based, while the arrays are 0 based ) 
NOTE
You are not allowed to modify the array ( The array is read only ).
Try to do it using constant extra space.

Example:
A : [2 1 4 3 2]
k : 3
answer : 2
*/

int Solution::kthsmallest(const vector<int> &A, int B) {
    priority_queue<int>q;
    int i;
    for(i=0;i<B;i++){
        q.push(A[i]);
    }
    for(;i<A.size();i++){
        if(A[i]<q.top()){
            q.pop();
            q.push(A[i]);
        }
    }
    return q.top();
}

// or

int Solution::kthsmallest(const vector<int> &A, int B) {
    vector<int>a = A;
    sort(a.begin(), a.end());
    return a[B-1];
}
