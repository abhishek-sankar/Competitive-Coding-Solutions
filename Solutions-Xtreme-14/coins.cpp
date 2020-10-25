#include<bits/stdc++.h>
using namespace std;
int getId(string s){
	if(s.compare("Zulian")==0)return 0;
	else if((s[0]=='R') && (s.compare("Razzashi")==0))return 1;
	else if((s[0]=='H')&&(s.compare("Hakkari")==0))return 2;
	else if((s[0]=='S')&&(s.compare("Sandfury")==0))return 3;
	else if((s[0]=='S')&&(s.compare("Skullsplitter")==0))return 4;
	else if((s[0]=='B')&&(s.compare("Bloodscalp")==0))return 5;
	else if((s[0]=='G')&&s.compare("Gurubashi")==0)return 6;
	else if((s[0]=='V')&&s.compare("Vilebranch")==0)return 7;
	else return 8;
}
int main(){
	int n, m, count;
	float cost;
	cin>>n>>m;
	string name;
	vector<int>coin_count(9);
	vector<int>is_available(9);
	vector<float>coin_cost(9);
	for(int i=0;i<m;i++){
		cin>>name>>count>>cost;
		int id = getId(name);
		cout<<id<<endl;
		coin_count[id]+=count;
		coin_cost[id] = cost;
		is_available[id] = 1;
		cout<<name<<" "<<coin_count[id]<<" "<<cost<<endl;
	}
	for(int i=0;i<9;i++){
		cout<<i<<" "<<coin_count[i]<<" "<<coin_cost[i]<<endl;
	}
	int count_1, count_2, count_3;
	float cost_1=0, cost_2=0, cost_3=0;
	count_1 = min(coin_count[0], min(coin_count[1], coin_count[2]));
	count_2 = min(coin_count[3], min(coin_count[4], coin_count[5]));
	count_3 = min(coin_count[6], min(coin_count[7], coin_count[8]));
	cout<<count_1<<" "<<count_2<<" "<<count_3<<endl;
	if(count_1>0)
	cost_1 = coin_cost[0] + coin_cost[1] + coin_cost[2];
	if(count_2>0)
	cost_1 = coin_cost[3] + coin_cost[4] + coin_cost[5];
	if(count_3>0)
	cost_1 = coin_cost[6] + coin_cost[7] + coin_cost[8];
	cout<<cost_1<<" "<<cost_2<<" "<<cost_3<<endl;
	if(count_1+count_2+count_3<n){
		// cout<<count_1<<" "<<count_2<<" "<<count_3<<endl;
		cout<<"impossible"<<endl;
		return 0;
	}
	int current_count = 0;
	cost = 0;
	
	while(n<current_count){
		if(cost_1 ==  min(cost_1,min(cost_2, cost_3)) && count_1>0){
			current_count+=min(n-current_count, count_1);
			cost+=min(n-current_count, count_1)*cost_1;
			count_1-=min(n-current_count, count_1);
		}else if(cost_2 == min(cost_2, cost_3) && count_2>0){
			current_count+=min(n-current_count, count_2);
			cost+=min(n-current_count, count_2)*cost_2;
			count_2-=min(n-current_count, count_2);
		}else if(count_3>0){
			current_count+=min(n-current_count, count_3);
			cost+=min(n-current_count, count_3)*cost_3;
			count_3-=min(n-current_count, count_3);
		}
	}
	cout<<cost<<endl;
	return 0;
}
/*
Set I: Zulian Coin \times 1×1, Razzashi Coin \times 1×1, and Hakkari Coin \times 1×1
Set II: Sandfury Coin \times 1×1, Skullsplitter Coin \times 1×1, and Bloodscalp Coin \times 1×1
Set III: Gurubashi Coin \times 1×1, Vilebranch Coin \times 1×1, and Witherbark Coin \times 1×1
*/