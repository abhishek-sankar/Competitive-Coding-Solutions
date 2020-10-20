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
    for(int i=1; i<4 && (builderIndex+i)<S.size()-1;i++){
        string sub = S.substr(builderIndex, i);
		cout<<"substring: "<<sub<<endl;
        int val = stoi(sub);
        if(val>255 || i>=2 && S[builderIndex]=='0'){
            break;
        }else{
            path[segment] = val;
			cout<<"Added val to path "<<val<<endl;
			for(int i=0;i<=segment;i++){
				cout<<path[i]<<".";
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