/*
To help verify the May 2020's Ponder This** challenge, May 2020 Ponder This, you need to write a simulator for a special version of Conway's game-of-life. In this game the board is cyclic (torus): the top of the board is connected to the bottom of the board and the left of the board is connected to the right of the board. We count the neighbors along common edges, so there are only 44 neighbors instead of the 88 neighbors found in the standard game-of-life.

Given the update rules for the empty cells and the live cells, and knowing the initial board, determine the final board state after a number of generations of the game.


Standard input
The input has the two update rules on the first line, separated by a semi-colon ;. Each rule is given with exactly 55 bits of zeroes and ones. Empty cells should be updated using the first rule, and live cells should be updated using the second rule.


For empty cells, a 1 in the ii-th bit of the rule sequence means that a live cell shall be born if exactly i - 1i−1 of its 44 neighbors are alive. Otherwise, the cell stays empty. For live cells, a 1 in ii-th bit in the rule sequence means that a live cell shall stay live if exactly i - 1i−1 of its 44 neighbors are also alive. Otherwise, the live cell becomes empty.

The second line of the input contains two integers NN and MM, indicating that the board is of size N \times NN×N and the number of generations to simulate is MM.

The next NN lines each have NN bits of zeroes and ones, giving the initial state of the board. A live cell is denoted by a 1, and an empty cell is denoted by 0.


Standard output
Output the final board state after MM generations. The output should contain NN rows with each row containing NN bits of 0s and 1s.


Constraints and notes
3 \leq N \leq 253≤N≤25
1 \leq M \leq 1\,0001≤M≤1000

Input	Output	Explanation
00100;11000
3 100
000
010
000
000
010
000
The rules are that an empty cell becomes live if and only if it has 22 neighbors; and a live cell stays if and only if it has zero or one neighbors. So the board stays the same even after 100100 generations.

01100;01100
4 1
0000
1000
1000
0000
1000
1101
1101
1000
Cells are born on all sides of the existing two cells. Since the board is cyclic, the left of the cells is at the rightmost of the board.

10000;01100
10 4
0000000000
0000000000
0000000000
0000000000
0000100000
0000000000
0000000000
0000000000
0000000000
0000000000
0000000000
0000000000
0010101000
0001010000
0010101000
0001010000
0010101000
0000000000
0000000000
0000000000
An empty board with this rule will oscillate between empty and full board. The single interference in the middle "explodes" outwards.

10000;01100
10 100
0000000000
0000000000
0000000000
0000000000
0000100000
0000000000
0000000000
0000000000
0000000000
0000000000
0010101000
0101010101
1000100010
0101010101
1010101011
0101010101
1000100010
0101010101
0010101000
0101110100
This is the same as the previous sample, but it runs for 100100 generations.

*/

#include <bits/stdc++.h>

#define fastio() \
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

typedef long long ll;

const int N = 26;
char grid[N][N], tmp[N][N];
bitset<5> live, dead;

int surr(int i, int j, int n) {
	int s = 0;
	if (grid[(i + n - 1)%n][j] == '1') ++s;
	if (grid[i][(j + n - 1)%n] == '1') ++s;
	if (grid[(i + 1)%n][j] == '1') ++s;
	if (grid[i][(j + 1)%n] == '1') ++s;
	return s;
}

int main() {
  fastio();
	live.reset();
	dead.reset();
	string rules;
	cin >> rules;
	for (int i = 0; i < 5; ++i) {
		dead[i] = rules[i] == '1';
		live[i] = rules[i + 6] == '1';
	}
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> grid[i][j];
		}
	}
	int s;
	while (m--) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				s = surr(i, j, n);
				if (grid[i][j] == '0') {
					if (dead[s]) {
						tmp[i][j] = '1';
					} else {
						tmp[i][j] = '0';
					}
				} else {
					if (live[s]) {
						tmp[i][j] = '1';
					} else {
						tmp[i][j] = '0';
					}
				}
			}
		}
		swap(tmp, grid);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << grid[i][j];
		}
		cout << '\n';
	}
  return 0;
}
