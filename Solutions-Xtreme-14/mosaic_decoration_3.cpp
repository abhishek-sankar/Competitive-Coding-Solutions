/*
Zapray lives in a big mansion that has many bathrooms. He wants to decorate one bathroom wall using mosaic tiles. The bathroom wall can be viewed as a grid of NN rows and MM columns of cells. Each mosaic tile covers exactly one cell on the wall. Zapray has a base pattern of mosaic tiles that has RR rows and CC columns. Each tile in the base pattern has some color labeled by a positive integer. Zapray will first choose one location on the wall to place the base pattern, and then he will repeat the base pattern horizontally and vertically to cover the entire wall.


In the example below, the wall has N=5, M=8N=5,M=8, and the base pattern has R=2, C=3R=2,C=3. The base pattern has tiles of four different colors labeled 1, 2, 3, 51,2,3,5. If Zapray chooses to place the base pattern at the top-left of the wall, the pattern will fill the wall as shown in the first image. If Zapray moves the base pattern to the right by two columns, and to the bottom by one row, the pattern will fill the wall as shown in the second image.





For any color labeled cc, Zapray can purchase one mosaic tile of that color for cc dollars. If Zapray chooses to place the base pattern at the best location and then fill the wall, what is the minimum total cost he has to pay to have the entire wall decorated by mosaic tiles?


Standard input
The input has four integers N, M, R, CN,M,R,C on the first line.

The next RR lines each have CC positive integers, giving the mosaic tile colors in the base pattern.


Standard output
Output a single integer, the minimum total cost in dollars that Zapray needs to pay.


Constraints and notes
1 \leq N, M \leq 10^61≤N,M≤10
​6
​​ 
1 \leq R \leq \min(50, N), 1 \leq C \leq \min(50,M)1≤R≤min(50,N),1≤C≤min(50,M)
All color labels are between 11 and 10^610
​6
​​ .

Input	Output	Explanation
5 8 2 3
5 2 3
2 3 1
98
This test case is illustrated in the figure above. The second base pattern location gives the optimal solution that needs 44 tiles of color 55 (shown in red), 1212 tiles of color 22 (shown in blue), 1515 tiles of color 33 (shown in orange), and 99 tiles of color 11 (shown in green). The total cost is 4 \times 5 + 12 \times 2 + 15 \times 3 + 9 \times 1 = 984×5+12×2+15×3+9×1=98 dollars.
*/

#include <bits/stdc++.h>

#define fastio() \
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

typedef long long ll;

int main() {
  fastio();
  ll w, h, a, b, m, c;
  cin >> w >> h >> a >> b >> m >> c;
  ll a1 = ceil(w / (a + 0.0));
  ll b1 = ceil(h / (b + 0.0));
  ll tiles = a1 * b1;
  ll buy = ceil(tiles / 10.0);
  ll ans = buy * m;
  if (a1 * a != w) ans += c * h;
  if (b1 * b != h) ans += c * w;
  cout << ans << '\n';
  return 0;
}