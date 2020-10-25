/*
Zapray has been playing the game World of Warcraft Classic. In the game, he needs to collect coins to exchange for rewards from a tribe. There are 99 kinds of coins he could collect. He can turn in the following combinations of coins for rewards, as many times as he likes.

Set I: Zulian Coin \times 1×1, Razzashi Coin \times 1×1, and Hakkari Coin \times 1×1
Set II: Sandfury Coin \times 1×1, Skullsplitter Coin \times 1×1, and Bloodscalp Coin \times 1×1
Set III: Gurubashi Coin \times 1×1, Vilebranch Coin \times 1×1, and Witherbark Coin \times 1×1
Each completed set gives the same rewards. Zapray has figured out he wants NN sets of coins for the rewards, thus he is going to buy the coins from other players via the Auction House. Each of the listings on the Auction House always consists a number of the same kind of coins with a buyout price.

Now Zapray needs your help to find out the minimum amount of money to complete NN sets of coins.

Standard input
The first line of input consists two integers NN and MM.

Each of the next MM lines describes a listing of coins on the Auction House with the name of the coin, quantity KK as an integer and price PP as an integer, separated by spaces. For example, Zulian 3 100 means 33 Zulian Coins are listed at a price of 100100.

Zapray cannot partially buy a listing.

Standard output
If it is impossible, output a single line impossible. Otherwise, output the minimum amount of money Zapray has to spend on completing NN sets of coins.

Constraints and notes
0 \leq N \leq 10000≤N≤1000
0 \leq M \leq 50000≤M≤5000
0 < K \leq 2500<K≤250
0 < P \leq 10^{6}0<P≤10
​6
​​ 
Coin names in the input are case-sensitive, and each coin name is exactly one of the 99 coin names as in the statement.
World of Warcraft Classic is developed and released by Blizzard Entertainment. Blizzard Entertainment does not endorse and has no involvement with IEEEXtreme 14.0 contest.

Input	Output	Explanation
10 8
Zulian 3 100
Sandfury 5 500
Skullsplitter 6 900
Bloodscalp 5 400
Razzashi 5 125
Hakkari 7 375
Witherbark 7 60
Zulian 4 800
3200
Zapray needs to buy all listings except for Witherbark Coins to complete 1010 sets.

10 3
Zulian 100 100
Sandfury 100 100
Gurubashi 100 100
impossible
There is no possible ways to complete enough sets.
*/

#include<bits/stdc++.h>
using namespace std;
int getId(string s){
	if(s.compare("Zulian")==0)return 0;
	else if((s[0]=='R') && (s.compare("Razzashi")))return 1;
	else if((s[0]=='H')&&(s.compare("Hakkari")))return 2;
	else if((s[0]=='S')&&(s.compare("Sandfury")))return 3;
	else if((s[0]=='S')&&(s.compare("Skullsplitter")))return 4;
	else if((s[0]=='B')&&(s.compare("Bloodscalp")))return 5;
	else if((s[0]=='G')&&s.compare("Gurubashi"))return 6;
	else if((s[0]=='V')&&s.compare("Vilebranch"))return 7;
	else if((s[0]=='W')&&s.compare("Witherbark"))return 8;
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
		coin_count[id]+=count;
		coin_cost[id] = cost;
		is_available[id] = 1;
	}
	int count_1, count_2, count_3;
	float cost_1, cost_2, cost_3;
	count_1 = min(coin_count[0], min(coin_count[1], coin_count[2]));
	count_2 = min(coin_count[3], min(coin_count[4], coin_count[5]));
	count_3 = min(coin_count[6], min(coin_count[7], coin_count[8]));
	if(count_1>0)
	cost_1 = coin_cost[0] + coin_cost[1] + coin_cost[2];
	if(count_2>0)
	cost_1 = coin_cost[3] + coin_cost[4] + coin_cost[5];
	if(count_3>0)
	cost_1 = coin_cost[6] + coin_cost[7] + coin_cost[8];
	if(count_1+count_2+count_3<n)cout<<"impossible"<<endl;
	
}
/*
Set I: Zulian Coin \times 1×1, Razzashi Coin \times 1×1, and Hakkari Coin \times 1×1
Set II: Sandfury Coin \times 1×1, Skullsplitter Coin \times 1×1, and Bloodscalp Coin \times 1×1
Set III: Gurubashi Coin \times 1×1, Vilebranch Coin \times 1×1, and Witherbark Coin \times 1×1
*/