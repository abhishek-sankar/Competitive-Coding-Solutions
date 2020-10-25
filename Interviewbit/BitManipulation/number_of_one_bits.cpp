/*
https://www.interviewbit.com/problems/number-of-1-bits/
Number of 1 Bits
Asked in:  Adobe, Yahoo
Write a function that takes an unsigned integer and returns the number of 1 bits it has.

Example:
The 32-bit integer 11 has binary representation
00000000000000000000000000001011
so the function should return 3.

Note that since Java does not have unsigned int, use long for Java

*/

int Solution::numSetBits(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int count = 0;
    for(int i=0;i<32;i++){
        count+= A&1;
        // cout<<"i: "<<i<<" count: "<<count<<" A "<<A<<endl;
        A = A >> 1;
    }
    return count;
}
