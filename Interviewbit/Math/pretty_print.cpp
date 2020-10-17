/*
https://www.interviewbit.com/problems/prettyprint/
PRETTYPRINT
Bookmark Suggest Edit
Print concentric rectangular pattern in a 2d matrix. 
Let us show you some examples to clarify what we mean.

Example 1:
Input: A = 4.
Output:

4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4 
Example 2:

Input: A = 3.
Output:

3 3 3 3 3 
3 2 2 2 3 
3 2 1 2 3 
3 2 2 2 3 
3 3 3 3 3 

The outermost rectangle is formed by A, then the next outermost is formed by A-1 and so on.
You will be given A as an argument to the function you need to implement, and you need to return a 2D array.
*/
vector<vector<int> > Solution::prettyPrint(int A) {
    vector<vector<int>>res;
    for(int i=0;i<2*A-1;i++){
        vector<int>smallRes;
        for(int j=0;j<2*A-1;j++){
            smallRes.push_back(0);
        }
        res.push_back(smallRes);
    }
    int flag = 0;
    int top = 0, bottom = 2*A-2, left = 0, right = 2*A-2;
    while(top<=bottom && left<=right){
        // cout<<"inside loop"<<endl;
        int val = A-top;
        if(flag==0){
            // cout<<"flag:0"<<endl;
            for(int i=left;i<=right;i++){
                res[top][i]=val;
            }
            top++;
        flag = (flag+1)%4;
        }
        if(flag==1){
            // cout<<"flag:1"<<endl;
            for(int i=top;i<=bottom;i++){
                res[i][right] = val;
            }
            right--;
            flag = (flag+1)%4;
        }
        if(flag==2){
            // cout<<"flag:2"<<endl;
            for(int i=right;i>=left;i--){
                res[bottom][i] = val;
            }
            bottom--;
        flag = (flag+1)%4;
        }
        if(flag==3){
            // cout<<"flag:3"<<endl;
            for(int i=bottom; i>=top;i--){
                res[i][left] = val;
            }
            left++;
        flag = (flag+1)%4;
        }
    }
    return res;
}
