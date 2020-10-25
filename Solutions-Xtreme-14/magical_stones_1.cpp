/*
You are practicing your alchemy skill over a pile of magical stones. A magical stone has NN possible states numbered from 11 to NN. In the beginning, you have exactly one magical stone that is in each state ii.


You know one magic spell. When you cast the spell, a stone that is in state ii will transform into a stone in state S_iS
​i
​​ . Whenever two stones are in a same state ii, they will purify each other, and combine into a single more powerful stone in state ii. Multiple stones in a same state will combine at the same time.


You would like to obtain exactly KK magical stones in the end. What is the minimum number of spells you have to cast to achieve that? Since you are not sure which KK best satisfies your needs, you are going to answer this question for many choices of KK.


Standard input
The input has a single integer NN on the first line.

The second line has NN integers. The ii-th is S_iS
​i
​​ .

The next line has a single integer QQ.

Each of the next QQ lines has a single integer KK as a query, for which you need to determine the minimum number spells required to obtain exactly KK magical stones.


Standard output
For each query, output the minimum number of spells required on a single line. If it is impossible to obtain exactly KK stones, output -1−1.


Constraints and notes
2 \leq N \leq 10^52≤N≤10
​5
​​ 
1 \leq S_i \leq N1≤S
​i
​​ ≤N. It is possible that S_i = iS
​i
​​ =i.
1 \leq Q \leq 10^51≤Q≤10
​5
​​ 
In all queries 1 \leq K < N1≤K<N
For 50\%50% of the test data, N \leq 1\,000, Q \leq 1\, 000N≤1000,Q≤1000.

Input	Output	Explanation
5
3 3 2 3 1
4
3
2
1
4
1
2
-1
-1
Initially, you have one stone in each of the 55 states \{1,2,3,4,5\}{1,2,3,4,5}. When you cast the first spell, the stone state in 33 transforms to state 22 (S_3=2S
​3
​​ =2). The stone in state 55 transforms to state 11 (S_5=1S
​5
​​ =1). The stones in state 1, 2, 41,2,4 transform to state 33 (S_1,S_2,S_4=3S
​1
​​ ,S
​2
​​ ,S
​4
​​ =3). They purify each other and become one stone in state 33. Therefore after one spell, you will have three stones in states \{1,2,3\}{1,2,3}. After a second spell, you will have two stones in states \{2, 3\}{2,3}. You will not be able to combine the last two stones into one. You also cannot obtain four stones.


*/

        #include <bits/stdc++.h> 
        using namespace std; 

        typedef long long int ll;

        struct Node { 
            int value = -1; 
        }; 

        int main(){
            ll n, t;
            cin >> n;

            vector<int> magis;
            set<int, greater<int> > spellSet;

            
            vector<int> res;
            res.push_back(n);

            for (int i = 0; i < n; i++){
                ll x;
                cin >> x;
                magis.push_back(x);
                spellSet.insert(i+1);
            }

            res.push_back(spellSet.size());

            bool change = true;
            ll spellSize = spellSet.size();
            cin >> t;
            std::vector<int>::iterator it; 
            ll val;
            cin >> val;
            t--;

            while(change){
                change = false;
                set<int, greater<int> >::iterator itr;
                set<int, greater<int> > spellTemp;
                
                for (itr = spellSet.begin(); itr != spellSet.end(); ++itr){
                    spellTemp.insert(*itr);
                    // cout << *itr << " ";
                }
                // cout << endl;

                spellSet.clear();
                for (itr = spellTemp.begin(); itr != spellTemp.end(); ++itr){
                    spellSet.insert(magis[*itr-1]);

                    // cout << *itr << "G" << magis[*itr-1] << endl;
                }

                if (spellSet.size() != spellSize){
                    change = true;
                    spellSize = spellSet.size();
                    res.push_back(spellSize);
                    // cout << spellSize << "F" << endl;
                }

                it = std::find (res.begin(), res.end(), val); 
                if (it != res.end()) 
                { 
                    cout << it - res.begin() -1  << endl ; 

                    if (t >= 0){
                        cin >> val;
                        t--;
                    }
                } 
                else if (val > spellSize){
                    cout << "-1\n";
                    if (t >= 0){
                        cin >> val;
                        t--;
                    }
                }

            }

            it = std::find (res.begin(), res.end(), val); 
            if (it != res.end()) 
            { 
                cout << it - res.begin() -1  << endl ; 
            }
            else
                cout << "-1\n"; 
                
            for (int i = 0; i < t; i++){
                ll val;
                cin >> val;

                it = std::find (res.begin(), res.end(), val); 
                if (it != res.end()) 
                { 
                    cout << it - res.begin() -1 << endl ; 
                } 
                else
                    cout << "-1\n"; 
            }

            return 0;
        }