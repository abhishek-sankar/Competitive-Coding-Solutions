/*
https://www.interviewbit.com/problems/add-one-to-number/
Given a non-negative number represented as an array of digits,
add 1 to the number ( increment the number represented by the digits ).
The digits are stored such that the most significant digit is at the head of the list.
If the vector has [1, 2, 3]
the returned vector should be [1, 2, 4]
as 123 + 1 = 124.
*/

vector<int> Solution::plusOne(vector<int> &A) {
    int carry = 0;
    reverse(A.begin(), A.end());
    A[0]+=1;
    if(A[0]>9){
        carry = A[0]/10;
        A[0] = A[0]%10;
    }
    int i=1;
    while(carry && i<A.size()){
        A[i]+=carry;
        carry = A[i]/10;
        if(A[i]>10){
            A[i]= A[i]%10;
        }
        i++;
    }
    if(i==A.size()){
        A.push_back(carry);
    }
    reverse(A.begin(), A.end());
    if(A[0]==0){
        A.erase(A.begin());
    }
    return A;
}
