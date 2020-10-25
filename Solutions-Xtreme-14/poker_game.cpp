/*
Tommy is playing a special Poker game with a standard deck of 5252 cards (Jokers excluded). There are four cards of each number: 2, 3, ..., 9, X, J, Q, K, A (X stands for 1010). The suits of cards do not matter in this game, and cards of a same number are completely equivalent. Most winning hands in the original Poker game, such as flush and full house, are not available.


Tommy is dealt KK cards as his initial hand. Then NN community cards are dealt one by one. At any time, Tommy's hand is Tommy's initial hand cards combined with the community cards. Tommy scores points if his hand meets the following categories:

Pair: Two cards of a same number give 11 point.
Three of a kind: Three cards of a same number give 2020 points.
Four of a kind: Four cards of a same number give 1\,7601760 points.
For each unique card number, Tommy receives the highest points among these three. Tommy's final points are the sum of points he receives for each unique card number. For example, if Tommy's hand has a pair of 2s, a pair of 8s, three As, and four K, he scores 1 + 1 + 20 + 1\,760 = 17821+1+20+1760=1782 points.


Tommy is not good at this Poker so he plays with a fixed simple strategy: Once a community card is dealt, if his points increase, he will raise the bet. Otherwise, he checks. No raise is allowed before the first community card is dealt.


You are watching Tommy playing this game, and you saw whether Tommy raised after each community card is revealed. You cannot help but wonder, what initial hand can Tommy possibly have?


Standard input
The input begins with two integers NN and KK on the first line.

The next line has a string of length NN describing the community cards dealt in order.

The third line has a string of length NN describing Tommy's actions after each community card. The ii-th character is y if Tommy raised after the ii-th community card, or n otherwise.


Standard output
Output a single line with the initial hand Tommy may have. Output the cards in the hand in sorted lexicographical order. If there are multiple possible hands, output the hand that gives the highest score. If there are still multiple hands, output the hand that is lexicographically the smallest.

The lexicographical order is defined over card numbers: 2 < 3 < ... < 9 < X < J < Q < K < A. For example, a hand with two 7s, one 3, one A and one X should be printed as 377XA. The hand 377XA is lexicographically smaller than 377KA.

If Tommy's actions contradict with his assumed strategy, output a single word impossible.


Constraints and notes
2 \leq K \leq 92≤K≤9
1 \leq N \leq 52 - K1≤N≤52−K
The community cards present a valid deck of cards. For example, there will not be five cards of a same number.

Input	Output	Explanation
9 2
AA9Q3776J
nyynnnynn
99
Tommy did not raise after the first A indicates that Tommy does not have A. Tommy raised after the second A because he got a pair and his score increased. Tommy raised immediately after the first 9 thus he must have a 9 in his initial hand. His other card cannot be uniquely determined. But that card cannot be A, Q, 3, 7, 6, J, so there are seven possibilities remaining: 29, 49, 59, 89, 99, 9X, 9K. Among them 99 gives the highest 2222 points.

3 2
234
yyy
impossible
Tommy raised immediately after the first 2, 3, 4. This indicates that Tommy has 2, 3, 4 in his initial hand. However only two cards are dealt for the initial hand. Therefore this contradicts Tommy's strategy.

3 2
XXX
nyn
impossible
Tommy's score must increase after the third X is dealt. Tommy must raise according to his strategy but he didn't.

8 3
234567AK
nnnnnnyy
KKA
Two hands give a highest score of 2121 points: KKA and KAA. KKA is lexicographically smaller.
*/

#include <bits/stdc++.h> 
using namespace std; 

typedef long long int ll;

int convertAlpha(char ch){
    if ((int)ch >= 50 && (int)ch <= 57){
        return (int)ch - 48;
    }

    if (ch == 'X') return 10;
    if (ch == 'J') return 11;
    if (ch == 'Q') return 12;
    if (ch == 'K') return 13;
    if (ch == 'A') return 14;
}


char convertNum(int n){
    if (n >= 2 && n <= 9){
        return (char)n + 48;
    }

    if (n == 10) return 'X';
    if (n == 11) return 'J';
    if (n == 12) return 'Q';
    if (n == 13) return 'K';
    if (n == 14) return 'A';
}

string arrange(string s){
    string res = "";
    for (int i = 48; i <= 57; i++){
        for (int j = 0; j < s.length(); j++){
            if ((char)i == s[j]){
                res += s[j];
            }
        }
    }

    string check = "XJQKA";
    for (int i = 0; i <= check.length(); i++){
        for (int j = 0; j < s.length(); j++){
            if ((char)check[i] == s[j]){
                res += s[j];
            }
        }
    }
    return res;
}

int main(){
    int n, k;
    cin >> n >> k;

    string community, raise;
    cin >> community >> raise;

    vector<int> arr(15, 0);

    for (int i = 0; i < n; i++){
        int ind = convertAlpha(community[i]);
        if (raise[i] == 'y' && arr[ind] != -1){
            arr[ind]++;
        }

        if (raise[i] == 'n' && arr[ind] > 0){
            cout << "impossible\n";
            return 0;
        }

        if (raise[i] == 'n'){
            arr[ind] = -1;
        }
        
        // cout << raise[i] << " " << community  << " " << arr[ind] << endl;
    }

    bool noVal = true;
    int valCount = 0;
    for (int i = 0; i < 15; i++){
        if (arr[i] > 0){
            noVal = false;
            valCount++;
        }
    }

    if (noVal || valCount > k){
        cout << "impossible\n";
        return 0;
    }

    string res = "";
    int i = 0;
    while(k){
        // cout << i << "F" << endl;
        if (i >= 15) i = 0;

        for (;i < 15; i++){
            if (arr[i] > 0) {res += convertNum(i); i++; k--; break;}
        }

        // cout << i << " " << res << endl;
    }
    
    res = arrange(res);
    cout << res << endl;
    return 0;
}