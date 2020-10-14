#include<bits/stdc++.h>

using namespace std;
bool checkIfAligned(int av1, int av2, int av3, int time){
	if((av1*time % 360 == av2*time % 360) && (av2*time % 360 == av3*time %360))
	return true;
	return false;
}

int main(){
	int noOfTestCases, angVel_1, angVel_2, angVel_3, r_1, r_2, r_3, time;
	cin>>noOfTestCases;
	for(auto i=0;i<noOfTestCases;i++){
		// cin>>r_1>>r_2>>r_3;
		cin>>angVel_1>>angVel_2>>angVel_3;
		cin>>time;
		cout<<checkIfAligned(angVel_1, angVel_2, angVel_3, time)<<endl;
		}
	return 0;
}