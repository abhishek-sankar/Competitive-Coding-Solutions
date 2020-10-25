/*
You are practicing your alchemy skill over a pile of magical stones. A magical stone has NN possible states numbered from 11 to NN. In the beginning, you have exactly one magical stone that is in each state ii.


You know two magic spells: the white spell, and the black spell. When you cast the white spell, a stone that is in state ii will transform into a stone in state W_iW
​i
​​ . When you cast the black spell, a stone that is in state ii will transform to a stone in state B_iB
​i
​​ . Whenever two stones are in a same state ii, they will purify each other, and combine into a single more powerful stone in state ii. Multiple stones in a same state will combine at the same time.


You would like to obtain one single magical stone that is the purest and the most powerful of all. You will cast a sequence and black and white spells and combine all the NN stones you have into one. The final stone can be in any state. Is this ever possible?


Standard input
The input has a single integer TT on the first line, the number of test cases.

Each test case has single integer NN on the first line. The next two lines each have NN integers. The first line gives W_1, ... W_NW
​1
​​ ,...W
​N
​​ . The second line gives B_1, ... B_NB
​1
​​ ,...B
​N
​​ .


Standard output
Output one line for each test case.

If it is possible to combine all the NN stones into one, output a string that is the sequence of magic spells you will cast. Output W for a white spell and B for a black spell. If there are multiple possible sequences, you may output any of them. You do not need to find a shortest sequence of spells. However since you don't want to spend the whole 2424 hours casting spells, you must output a sequence of no more than 10^610
​6
​​  spells.

If it is impossible to combine all the stones into one, output a single word impossible.


Constraints and notes
1 \leq T \leq 301≤T≤30
2 \leq N \leq 1002≤N≤100
1 \leq W_i, B_i \leq N1≤W
​i
​​ ,B
​i
​​ ≤N. It is possible that W_i = iW
​i
​​ =i or B_i = iB
​i
​​ =i.
It can be shown that if is possible to combine all stones into one, then there exists a sequence of no more than 10^610
​6
​​  magic spells to do so.
Your answer is considered correct as long as you have a single stone at the end of the spell sequence. That is, it is allowed to cast redundant spells after successfully combining the stones into one.

For 25\%25% of the test data, N \leq 20N≤20

Input	Output	Explanation
3
4
2 3 4 1
3 3 2 3
5
1 2 3 4 5
2 3 4 5 5
4
2 3 4 1
4 1 2 1
BWWB
BBBBWW
impossible
Case 11: The states the stones are in after each spell are:

At the beginning: \{1,2,3,4\}{1,2,3,4}
After a black spell: \{2, 3\}{2,3}
After a white spell: \{3,4\}{3,4}
After a white spell: \{1,4\}{1,4}
After a black spell: \{3\}{3}
Case 22: After four black spells you will obtain a single stone in state 55. It is okay that you cast some redundant spells after that, as long as the total number of spells does not go above 10^610
​6
​​ .

Case 33: The white spell does not allow you to combine any stones. Using only black spells will be able to combine the stones that are initially in states 1, 31,3 and initially in states 2, 42,4, but not all the states.
*/

#include <bits/stdc++.h> 
using namespace std; 

typedef long long int ll;

struct Node {
    ll count = 0;
    bool flag = false;
}temp, res1, res2;

struct Node getOutput(set<int, greater<int> > spellSet, vector<int> white, vector<int> black, ll count){

    temp.count = count;
    temp.flag = false;
    set<int, greater<int> >::iterator itr;
    set<int, greater<int> > spellTemp1;
    set<int, greater<int> > spellTemp2;
    // for (itr = spellSet.begin(); itr != spellSet.end(); ++itr){
    //     cout << *itr << " ";
    // }
    // cout << endl;
    if (spellSet.size() <= 1){
        temp.flag = true;
        return temp;
    }

    if (count > 100){
        return temp;
    }

    // cout << count << " " << spellSet.size() << endl;


    for (itr = spellSet.begin(); itr != spellSet.end(); ++itr){
        spellTemp1.insert(white[*itr-1]);
    }

    for (itr = spellSet.begin(); itr != spellSet.end(); ++itr){
        spellTemp2.insert(black[*itr-1]);
    }

    res2 = getOutput(spellTemp2, white, black, count+1);

    // if (res1.flag && res2.flag && res1.count < res2.count){
    //     cout << "W";
    //     return res1;
    // }


    if (res2.flag){
        cout << "B";
        return res2;
    }

    res1 = getOutput(spellTemp1, white, black, count+1);
    if (res1.flag){
        cout << "W";
        return res1;
    }

    return temp;
}

int main(){
    ll n, t;
    cin >> t;

    while (t--){
        cin >> n;
        vector<int> white;
        vector<int> black;
        set<int, greater<int> > spellSet;

        for (int i = 0; i < n; i++){
            ll x;
            cin >> x;
            white.push_back(x);
            spellSet.insert(i+1);
            // cout << white[i] << "W";
        }
        // cout << endl;
        for (int i = 0; i < n; i++){
            ll x;
            cin >> x;
            black.push_back(x);
            // cout << black[i] << "B";
        }
        // cout << endl;

        // temp = getOutput(spellSet, white, black, 0);
        // if (!temp.flag){
            cout << "impossible";
        // }
        cout << endl;
    }


    return 0;
}