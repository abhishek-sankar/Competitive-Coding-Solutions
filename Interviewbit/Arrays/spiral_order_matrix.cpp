/*
https://www.interviewbit.com/problems/spiral-order-matrix-i/
Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.
Example:
Given the following matrix:

[
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
]
You should return

[1, 2, 3, 6, 9, 8, 7, 4, 5]
*/

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int left = 0;
    int right = A[0].size()-1;
    int top = 0;
    int bottom = A.size()-1;
    int direction = 0;
    vector<int>v;
    while(top<=bottom && left<=right){
        direction = (direction+1)%4;
        if(direction==1){
            for(int i=left;i<=right;i++){
                v.push_back(A[top][i]);
            }
        top++;
        }
        if(direction==2){
            for(int i=top;i<=bottom;i++){
                v.push_back(A[i][right]);
            }
        right--;
        }
        if(direction==3){
            for(int i=right;i>=left;i--){
                v.push_back(A[bottom][i]);
            }
        bottom--;
        }
        if(direction==0){
            for(int i=bottom;i>=top;i--){
                v.push_back(A[i][left]);
            }
        left++;
        }
    }
    return v;
}
