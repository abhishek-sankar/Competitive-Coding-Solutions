#include<bits/stdc++.h>

using namespace std;
bool isValid(vector<int>cols){
	int rowId = cols.size()-1;
	for(int i=0;i<rowId;i++){
		int diff = abs(cols[i] - cols[rowId]);
		if(diff == 0 || diff == rowId - i)return 0;
	}
	return 1;
}
void findNQueens(vector<vector<int>>&board, int count, vector<int>&cols, int col){
	if(col==count){
		cout<<"col==count: "<<col<<endl;
		board.push_back(cols);
	}
	if(col<count){
		for(int i=0;i<count;i++){
			cols.push_back(i);
			if(isValid(cols)){
				findNQueens(board, count, cols, col+1);
			}
			cols.pop_back();
		}
	}

}
void printNQueen(vector<vector<int>>board, int count){
	for(int i=0;i<board.size();i++){
		for(int j=0;j<count;j++){
			for(int k=0;k<count;k++){
				if(board[i][j]==k) cout<<" Q ";
				else cout<<" X ";
			}
			cout<<endl;
		}
		cout<<endl<<endl;
	}
}
void nQueens(int count){
	vector<vector<int>> board;
	vector<int>cols;
	findNQueens(board, count, cols, 0);
	cout<<"Completed findNQueens"<<endl;
	printNQueen(board, count);
}


int main(){
	nQueens(8);
}