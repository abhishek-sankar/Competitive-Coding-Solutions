/*
As you may remember, in the IEEEXtreme 10.0 there was a challenge called Counting Molecules. In that challenge, you had a machine that counted the number of molecules in a cup of soda which contains distilled water (H_2OH
​2
​​ O), carbon dioxide (CO_2CO
​2
​​ ), and glucose (C_6H_{12}O_6C
​6
​​ H
​12
​​ O
​6
​​ ). Given a cup of sample liquid, the machine reported the number of atoms of carbon, hydrogen, and oxygen as three integers CC, HH, and OO respectively. You were asked to determine if the given number of atoms was consistent with a mixture containing only water, carbon dioxide, and glucose molecules. The answer could be Error when it was impossible to have a mixture of only water, carbon dioxide, and glucose molecules with the reported numbers of atoms.


In this challenge, you have the same machine that reports CC, HH, and OO for a given liquid sample. We ask you to find the smallest number of atoms that needs to be added and/or discarded so that it is possible that the sample is a mixture of only water, carbon dioxide, and glucose.


Standard input
The input contains a single integer TT on the first line, the number of test cases.

Each of the next TT lines has three integers CC, HH, and OO giving one test case.


Standard output
For each test case output the minimum number of atoms that needs to be added and/or discarded so that the sample becomes possibly a mixture of only water, carbon dioxide, and glucose. When the given numbers of atoms can already form a mixture of only water, carbon dioxide, and glucose, output zero.


Constraints and notes
1 \leq T \leq 401≤T≤40
0 \leq C, H, O \leq 10^60≤C,H,O≤10
​6
​​ 
It is allowed to discard all atoms. Zero atoms are considered a valid (empty) mixture.

Input	Output	Explanation
4
2 2 2
126 482 255
0 200 0
0 2 1
2
1
100
0
Test case 11: Adding one oxygen atom and removing a carbon atom makes it possible to be a mixture of 11 water molecule and 11 carbon dioxide molecule.
Test case 22: 77 molecules of CO_2CO
​2
​​ , 121121 molecules of water and 2020 molecules of glucose give 7+6*20=1277+6∗20=127 carbon atoms, 2*121+12*20=4822∗121+12∗20=482 hydrogen atoms, and 2*7+1*121+6*20=2552∗7+1∗121+6∗20=255 atoms of oxygen, yielding only one extra atom (carbon).
Test case 33: We may add 100100 oxygen atoms to have 100100 water molecules.
Test case 44: Without adding or discarding any atoms, a single water molecule may have the given atoms.


C++



*/

#include <bits/stdc++.h> 
using namespace std;

int main() 
{ 
    int t;
    cin >> t;

    while(t--){
        int c,h,o;
        cin >> c >> h >> o;
        int count = 0;

        if (c >= 6 && h >= 12 && o >= 6){
            int div = c/6;
            c = c%6;

            h -= 12*div;
            o -= 6*div; 
        }

        if (c >= 0 && o > 0){
            o -= 2*c;
        }else if (o <= 0){
            count += c;
        }

        if (h >= 0){
            if (h%2 != 0){
                count ++;
                h++;
            }

            o -= h/2;
        }

        count += abs(o);
        cout << count <<endl;
    }
	return 0; 
} 
