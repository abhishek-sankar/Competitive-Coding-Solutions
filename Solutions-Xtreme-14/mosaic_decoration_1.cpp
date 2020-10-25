/*
Zapray lives in a big mansion that has NN bathrooms. He wants to decorate the bathroom walls using mosaic tiles of two colors: black and pink. The iith bathroom needs B_iB
​i
​​  black tiles and P_iP
​i
​​  pink tiles. Mosaic tiles are sold in piles. Zapray can buy one pile of 1010 black tiles for C_BC
​B
​​  dollars, and one pile of 1010 pink tiles for C_PC
​P
​​  dollars. How much money does he need in total to decorate all the NN bathrooms?


Standard input
The input contains three integers N, C_B, C_PN,C
​B
​​ ,C
​P
​​  on the first line.

The next NN lines each have two integers. The iith line has B_iB
​i
​​  and P_iP
​i
​​ .


Standard output
Output a single integer, the amount of money in dollars that Zapray needs to decorate all his bathrooms.


Constraints and notes
2 \leq N \leq 1002≤N≤100
1 \leq C_B, C_P \leq 1\,0001≤C
​B
​​ ,C
​P
​​ ≤1000
1 \leq B_i, P_i \leq 1\,0001≤B
​i
​​ ,P
​i
​​ ≤1000

Input	Output	Explanation
3 5 7
10 10
20 30
30 3
65
There are 33 bathrooms to decorate. In total 6060 black tiles and 4343 pink tiles are needed. Zapray needs to purchase 66 piles of black tiles and 55 piles of pink tiles. The total cost is 6 \times 5 + 5 \times 7 = 656×5+5×7=65 dollars.
*/

#include <bits/stdc++.h>

#define fastio() \
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

typedef long long ll;

// const int N = 101;
// int b[N], p[N];

int main() {
  fastio();
  int n, cb, cp, sb, sp, b, p;
  cin >> n >> cb >> cp;
	sb = sp = 0;
	for (int i = 0; i < n; ++i) {
		cin >> b >> p;
		sb += b;
		sp += p;
	}
	int ans = ceil(sb/10.0)*cb + ceil(sp/10.0)*cp;
	cout << ans << '\n';
  return 0;
}
