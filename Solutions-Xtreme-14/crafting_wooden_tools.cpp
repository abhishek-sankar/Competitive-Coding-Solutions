/*
A lot of people are stuck at home due to the unfortunate pandemic this year. They thus resort to building their wonderful home on a deserted island. Rolan is such an deserted islander.


To live a fruitful life on a deserted island, Rolan needs to craft a lot of furniture. One of Rolan's favorite, is the wooden table. Crafting a wooden table requires CC pieces of wood, which is a resource obtainable by chopping trees on the island. Rolan has a pocket of limited size that can hold the wood and the crafted wooden tables. Her pocket has NN slots, and each slot can hold either a single wooden table, or a pile of wood with at most PP pieces of wood.


Rolan has WW pieces of wood at the beginning and can distribute them into the NN pocket slots arbitrarily. To craft a wooden table, Rolan takes CC pieces of wood from any of the pocket slots, removing them from those slots. If any pile of wood becomes empty, the pocket slot becomes free. If there is no free slot in Rolan's pocket, the crafting stops. Otherwise, the crafted wooden table will be placed in a free pocket slot. Rolan repeats the crafting until no more wooden tables can be crafted.


How many wooden tables will Rolan eventually have?


Standard input
The input has four integers C, N, P, WC,N,P,W on a single line.


Standard output
Output a single integer, the number of wooden tables that Rolan can craft.


Constraints and notes
1 \leq C, N, P, W \leq 10^{15}1≤C,N,P,W≤10
​15
​​ 
W \leq N \cdot PW≤N⋅P
For 60\%60% of the test data, C, N, P, W \leq 10^6C,N,P,W≤10
​6
​​ 

Input	Output	Explanation
4 3 3 8
2
Rolan distributes the wood into the pocket as [3, 3, 2][3,3,2]. Each integer denotes the number of wood pieces in a pile. Let TT denote a wooden table. The first crafted table will be placed as [3, 1, T][3,1,T]. Then a second table can be crafted and placed as [T, 0, T][T,0,T].

2 3 3 8
1
Initial pocket is [3, 3, 2][3,3,2]. Crafting a wooden table consumes 22 pieces of wood. Only one table can be crafted and the pocket is [3, 3, T][3,3,T].

10 3 3 8
0
Crafting a wooden table requires 1010 pieces of wood. But Rolan does not have that many pieces of wood.
*/

#include <bits/stdc++.h>

#define fastio() \
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

typedef long long ll;

int main() {
  fastio();
  ll c, n, p, w;
  cin >> c >> n >> p >> w;
  ll ans;
  if (c > w) {
    ans = 0;
  } else if (c == w) {
    ans = 1;
  } else if (c >= p) {
    ans = w/c;
  } else {
    double z = p - c;
    ll x = ceil(w/z - n/z*c);
    ans = n - x;
  }
  cout << ans << '\n';
  return 0;
}
