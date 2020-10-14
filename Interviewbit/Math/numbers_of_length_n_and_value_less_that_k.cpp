
#include <bits/stdc++.h>
using namespace std;
/*
The following code is to be used on interviewbit

int Solution::solve(vector<int> &v, int len, int max) {
    string lenStr = to_string(max);
	vector<int>dp(len+1, 0);
	if(len>lenStr.size() || v.size()==0){
		return 0;
	}else if(len==1){
		if(lenStr.size()==1){
		    int count = 0;
		    for(int i=0;i<v.size();i++){
		        if(v[i]<max)count++;
		    }
		    return count;
		}else{
		    return v.size();   
		}
	}else if(len<lenStr.size()){
		if(v[0]==0){
			return (v.size()-1)*pow(v.size(), len-1);
		}else{
			return pow(v.size(), len);
		}
	}else{
		vector<int>digit;
		for(int i=0; i<lenStr.size();i++){
			digit.push_back(lenStr[i]-48);
		}
		// for(int i=0;i<digit.size();i++){
		// 	cout<<digit[i]<<" ";
		// }
		vector<int>lower(10,0);
		int low = v[0];
		for(int i=0;i<v.size();i++){
			// cout<<"Current i"<<i<<endl;
			for(int j=v[i]+1;j<lower.size();j++){
				// cout<<"Current j, v[j]"<<j<<" "<<endl;
				lower[j]++;
			}
		}
		vector<int>same(digit.size(),0);
		for(int i=0;i<digit.size();i++){
			for(int j=0;j<v.size();j++){
				if(digit[i]==v[j] && i!=0 && same[i-1]==i){
					same[i] = i+1;
				}else if(i==0 && digit[i]==v[j]){
					same[i] = 1;
				}
			}
		}
// 		for(int i=0;i<lower.size();i++)cout<<lower[i]<<" ";
// 		cout<<endl;
// 		for(int i=0;i<same.size();i++)cout<<same[i]<<" ";
// 		cout<<endl;
		dp[0] = lower[digit[0]];
		if(v[0]==0 && len!=1)dp[0]--;
		for(int i=1;i<len;i++){
		  //  cout<<"i: "<<i<<endl;
			dp[i] +=dp[i-1]*v.size();
// 			cout<<dp[i]<<" ";
			if(same[i-1]==i)
			dp[i]+=lower[digit[i]];
// 			cout<<dp[i]<<endl;
		}
// 		for(int i=1;i<=len;i++){
// 			cout<<dp[i]<<" ";
// 		}
        // cout<<endl;
	}
	return dp[len-1];
}

*/
int getResult(vector<int>v, int len, int max){
	string lenStr = to_string(max);
	vector<int>dp(len, 0);
	if(len>lenStr.size() || v.size()==0){
		return 0;
	}else if(len==1){
		return v.size();
	}else if(len<lenStr.size()){
		if(v[0]==0){
			return (v.size()-1)*pow(v.size(), len-1);
		}else{
			return pow(v.size(), len);
		}
	}else{
		vector<int>digit;
		for(int i=0; i<lenStr.size();i++){
			digit.push_back(lenStr[i]-48);
		}
		// for(int i=0;i<digit.size();i++){
		// 	cout<<digit[i]<<" ";
		// }
		vector<int>lower(10,0);
		int low = v[0];
		for(int i=0;i<v.size();i++){
			// cout<<"Current i"<<i<<endl;
			for(int j=v[i]+1;j<lower.size();j++){
				// cout<<"Current j, v[j]"<<j<<" "<<endl;
				lower[j]++;
			}
		}
		vector<int>same(digit.size());
		for(int i=0;i<digit.size();i++){
			for(int j=0;j<v.size();j++){
				if(digit[i]==v[j] && i!=0 && same[i-1]==i){
					same[i] = i+1;
				}else if(i==0 && digit[i]==v[j]){
					same[i] = 1;
				}
			}
		}
		// for(int i=0;i<lower.size();i++)cout<<lower[i]<<" ";
		// cout<<endl;
		dp[0] += lower[digit[0]];
		if(v[0]==0 && len!=1)dp[0]--;
		for(int i=1;i<=len;i++){
			dp[i] +=dp[i-1]*v.size();
			if(same[i-1]==i)
			dp[i]+=lower[digit[i]];
		}
		// for(int i=1;i<=len;i++){
		// 	cout<<dp[i]<<endl;
		// }
	}
	return dp[len-1];
}

int main(){
	int n, num, len, max;
	vector<int>v;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num;
		v.push_back(num);
	}
	cin>>len>>max;
	cout<<getResult(v, len, max)<<endl;
}