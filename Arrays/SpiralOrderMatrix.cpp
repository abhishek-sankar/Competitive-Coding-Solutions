vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    vector<int> B;
    int top = 0,bottom = A.size()-1,right = A[0].size()-1,left = 0,dir = 0;
    while(top<=bottom && left<=right){
        if(dir==0){
            for(int i=left;i<=right;i++){
                B.push_back(A[top][i]);
            }
            top++;
            dir=(dir+1)%4;
        }else if(dir==1){
            for(int i=top;i<=bottom;i++){
                B.push_back(A[i][right]);
            }
            right--;
            dir=(dir+1)%4;
        }else if(dir==2){
        	for(int i=right;i>=left;i--){
        	    B.push_back(A[bottom][i]);
        		}
    			bottom--;
    			dir = (dir+1)%4;
    	}else if(dir==3){
        	for(int i=bottom;i>=top;i--){
        	    B.push_back(A[i][left]);
        	}
        	left++;
        	dir = (dir+1)%4;
    	}
	}
    return B;
}