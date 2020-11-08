/*
https://www.interviewbit.com/problems/rotate-matrix/
*/

void Solution::rotate(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int temp = 0;
    for(int i=0;i<A.size();i++){
        for(int j=i+1;j<A[0].size();j++){
            temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }
    
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size()/2;j++){
            temp = A[i][j];
            A[i][j] = A[i][A[0].size()-j-1];
            A[i][A[0].size()-j-1] = temp;
        }
    }
    // return A;
}
