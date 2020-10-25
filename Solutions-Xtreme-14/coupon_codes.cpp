/*
Brett is running a new online goodie shop. The business is booming and it has attracted tens of thousands of customers! Yet Brett is ambitious and he would like to further expand his customer base. He will run a campaign that provides discount coupon codes to new customers.


Brett will generate NN coupon codes of the following format:

XXXX-XXXX-XXXX

where X is an uppercase letter A-Z or a digit 0-9.


At first Brett thought he'll just randomly generate these codes. Soon he realizes that there is a serious issue - people tend to mistype their codes. Brett definitely does not want to accept a mistyped code, otherwise one customer's discount may be used by another customer!


Brett would like to know among the NN coupon codes he generated how many pairs of them are similar. Two coupon codes are similar if their Hamming distance is exactly one. In other words, two coupon codes C_1, C_2C
​1
​​ ,C
​2
​​  are similar if you can change C_1C
​1
​​  into C_2C
​2
​​  by modifying exactly one character in C_1C
​1
​​ .


Standard input
The first line has a single integer NN.

Then NN lines follow. Each line has one coupon code.


Standard output
Output a single integer, the number of pairs of coupon codes that are similar.


Constraints and notes
2 \leq N \leq 10^{5}2≤N≤10
​5
​​ 
All coupon codes are distinct, and are valid according to the format above.
For 50\%50% of the test data, N \leq 100N≤100

Input	Output	Explanation
6
WELC-OMET-OTHE
IEEE-XTRE-ME14
AAAA-0000-A0A0
AAAA-0000-A0A1
AAAA-0000-A0AB
AAAA-0000-ABAB
4
There are 66 codes. If they are labeled from 11 to 66, the similar pairs are (3, 4), (3, 5), (4, 5), (5, 6)(3,4),(3,5),(4,5),(5,6).



C++



*/

#include <bits/stdc++.h> 

#define fastio() \
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

typedef long long int ll;

int main(){
    fastio();
    int n;
    cin >> n;

    vector<string> arr;

    for (int i = 0; i < n; i++){
        string x; cin >> x;
        arr.push_back(x);
    }

    int count = 0;
    for (int i = 0; i < n; i++){

        for (int j = i+1; j < n; j++){
            int check = 0;
            for (int k = 0; k < 14; k++){
                if (check > 1){
                    break;
                }
                // cout << arr[i][k] << arr[j][k] << " " << count << endl;
                if (arr[i][k] != arr[j][k]){
                    check ++;
                }
            }
            if (check == 1)
                count++;
        }
        
    }

    cout << count;

    return 0;
}