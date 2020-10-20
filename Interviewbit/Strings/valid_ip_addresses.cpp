/*
Valid Ip Addresses
Asked in:  
Amazon
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

Example:

Given “25525511135”,

return [“255.255.11.135”, “255.255.111.35”]. (Make sure the returned strings are sorted in order)
*/

#include<bits/stdc++.h>
using namespace std;

void findIPs(vector<string>&res, string S, int builderIndex, int (&path)[4], int segment){
    //goal or base case
	cout<<"BuildIndex: "<<builderIndex<<" Segment: "<<segment<<endl;
    if(segment == 4 && builderIndex == S.size()){
        //add path to list
		cout<<"Yes"<<endl;
        res.push_back(to_string(path[0])+"."+to_string(path[1])+"."+to_string(path[2])+"."+to_string(path[3]));
    }else if(segment == 4 || builderIndex == S.size()){
        return;
    }
    //constraint
	//255 255 11 135
    for(int i=1; i<4 && (builderIndex+i)<=S.size();i++){
        string sub = S.substr(builderIndex, i);
		cout<<"substring: "<<sub<<endl;
        int val = stoi(sub);
        if(val>255 || i>=2 && S[builderIndex]=='0'){
            break;
        }else{
            path[segment] = val;
			cout<<"Added val to path "<<val<<endl;
			for(int j=0;j<=segment;j++){
				cout<<path[j]<<".";
			}
			cout<<endl;
        }
        //choice
        findIPs(res, S, builderIndex+i, path, segment+1);
    }
}
vector<string> restoreIpAddresses(string A) {
    vector<string>res;
    int path[4] = {0};
	for(int i=0;i<4;i++){
		cout<<path[i]<<" ";
	}
	cout<<endl;
    findIPs(res, A, 0, path, 0);
    return res;
}
int main(){
	string str;
	cin>>str;
	vector<string>res = restoreIpAddresses(str);
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<endl;
	}
	return 0;
}
/*
void findIPs(vector<string>&res, string S, int builderIndex, int (&path)[4], int segment){
    //goal or base case
// 	cout<<"BuildIndex: "<<builderIndex<<" Segment: "<<segment<<endl;
    if(segment == 4 && builderIndex == S.size()){
        //add path to list
// 		cout<<"Yes"<<endl;
        res.push_back(to_string(path[0])+"."+to_string(path[1])+"."+to_string(path[2])+"."+to_string(path[3]));
    }else if(segment == 4 || builderIndex == S.size()){
        return;
    }
    //constraint
	//255 255 11 135
    for(int i=1; i<4 && (builderIndex+i)<=S.size();i++){
        string sub = S.substr(builderIndex, i);
// 		cout<<"substring: "<<sub<<endl;
        int val = stoi(sub);
        if(val>255 || i>=2 && S[builderIndex]=='0'){
            break;
        }else{
            path[segment] = val;
// 			cout<<"Added val to path "<<val<<endl;
// 			for(int j=0;j<=segment;j++){
// 				cout<<path[j]<<".";
// 			}
// 			cout<<endl;
        }
        //choice
        findIPs(res, S, builderIndex+i, path, segment+1);
    }
}
vector<string> Solution::restoreIpAddresses(string A) {
    vector<string>res;
    int path[4] = {0};
// 	for(int i=0;i<4;i++){
// 		cout<<path[i]<<" ";
// 	}
// 	cout<<endl;
    findIPs(res, A, 0, path, 0);
    sort(res.begin(), res.end());
    return res;
}

*/